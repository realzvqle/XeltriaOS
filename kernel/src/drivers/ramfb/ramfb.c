#include "ramfb.h"
#include "../mmio.h"
#include <stdint.h>


static volatile uint16_t *baseaddrsel = (uint16_t*)0x9020008;

extern fb_info fb;

// thanks to https://github.com/luickk/qemu-ramfb-aarch64-driver for the help!

static inline void QemuCFGDMATransfer(void* address, uint32_t length, uint32_t control){
    QemuCfgDmaAccess access = {.address = KiBSwap64((uint64_t)address), .length = KiBSwap32(length), .control = KiBSwap32(control)};
    if(length == 0){
        return;
    }
    __asm__("ISB");
    KiWriteBSwap64(BASE_ADDR_ADDR, (uint64_t)&access);
    while(KiBSwap32(access.control) & ~QEMU_CFG_DMA_CTL_ERROR){}
}

static inline void QemuCFGRead(void* buf, int len){
    QemuCFGDMATransfer(buf, len, QEMU_CFG_DMA_CTL_READ);
}

static inline void QemuCFGReadEntry(void* buf, int e, int len){
    uint32_t control = (e << 16) | QEMU_CFG_DMA_CTL_SELECT | QEMU_CFG_DMA_CTL_READ;
    QemuCFGDMATransfer(buf, len, control);
}

static inline void QemuCFGWriteEntry(void* buf, uint32_t e, uint32_t len){
    uint32_t control = (e << 16) | QEMU_CFG_DMA_CTL_SELECT | QEMU_CFG_DMA_CTL_WRITE;
    QemuCFGDMATransfer(buf, len, control);
}

static inline int QemuCFGFindFile(){
    uint32_t count, e, select;
    QemuCFGReadEntry(&count, QEMU_CFG_FILE_DIR, sizeof(count));
    count = KiBSwap32(count);

    for(select = 0, e = 0; e < count; e++){
        struct QemuCfgFile qfile;
        QemuCFGRead(&qfile, sizeof(qfile));
        if(KiCompareMemoryString(qfile.name, "etc/ramfb", 10) == 0) select = KiBSwap16(qfile.select);
    }
    return select;
}

static inline int CheckCFGDMA(){
    KiWrite16(baseaddrsel, 0x0000);
    union FwCfgSigRead cfg_sig_read;

    cfg_sig_read.theInt = *((volatile uint16_t*)BASE_ADDR_DATA);
    if (cfg_sig_read.bytes[0] == 'Q' && cfg_sig_read.bytes[1] == 'E' && cfg_sig_read.bytes[2] == 'M' && cfg_sig_read.bytes[3] == 'U') {
        if (KiReadBSWap64(BASE_ADDR_ADDR) == 0x51454d5520434647) {
            return 1;
        }
    } return 0;
}

void KiSetupFramebuffer(){
    extern uint64_t stack_beginning;
    uint64_t heap_start = (uint64_t)&stack_beginning;
    uint32_t fb_width = WIDTH;
    uint32_t fb_height = HEIGHT;
    uint32_t fb_bpp = 4;
    uint32_t fb_stride = fb_bpp * fb_width;
    fb = (fb_info){
        .fb_addr = heap_start,
        .fb_width = fb_width,
        .fb_height = fb_height,
        .fb_bpp = fb_bpp,

        .fb_stride = fb_stride,
        .fb_size = fb_stride * fb_height,
    };
}

int KiSetupRamFB(){
    uint32_t select = QemuCFGFindFile();
    if(select == 0){

        return 1;
    }

    struct QemuRAMFBCfg cfg = {
        .addr   = KiBSwap64(fb.fb_addr),
        .fourcc = KiBSwap32(DRM_FORMAT_XRGB8888),
        .flags  = KiBSwap32(0),
        .width  = KiBSwap32(fb.fb_width),
        .height = KiBSwap32(fb.fb_height),
        .stride = KiBSwap32(fb.fb_stride),
    };
    QemuCFGWriteEntry(&cfg, select, sizeof(cfg));
    return 0;
}




void KiWriteRGB256Pixel(fb_info *fb, uint16_t x, uint16_t y, uint8_t pixel[3]) {
    KiCopyMemory((void*)fb->fb_addr + ((y * fb->fb_stride) + (x * fb->fb_bpp)), pixel, 4);
}


void KiCreateRGB(uint8_t* color, uint8_t r, uint8_t g, uint8_t b){
    color[0] = b;
    color[1] = g;
    color[2] = r;
}