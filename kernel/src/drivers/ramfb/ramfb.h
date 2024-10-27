#ifndef RAMFB_H_INCLUDED
#define RAMFB_H_INCLUDED








#include "../../superheader.h"



#define QEMU_CFG_FILE_DIR               0x19

#define QEMU_CFG_DMA_CTL_ERROR   0x01
#define QEMU_CFG_DMA_CTL_READ    0x02
#define QEMU_CFG_DMA_CTL_SKIP    0x04
#define QEMU_CFG_DMA_CTL_SELECT  0x08
#define QEMU_CFG_DMA_CTL_WRITE   0x10

#define BASE_ADDR 0x09020000
#define BASE_ADDR_SELECTOR 0x9020008
#define BASE_ADDR_DATA 0x09020000
#define BASE_ADDR_ADDR 0x9020010

union FwCfgSigRead {
    uint32_t theInt;
    char bytes[sizeof(int)];
};

typedef struct {
    uint32_t control;
    uint32_t length;
    uint64_t address;
} __attribute__((__packed__)) QemuCfgDmaAccess;

struct __attribute__((__packed__)) QemuRAMFBCfg {
    uint64_t addr;
    uint32_t fourcc;
    uint32_t flags;
    uint32_t width;
    uint32_t height;
    uint32_t stride;
};

struct QemuCfgFile {
    uint32_t  size;       
    uint16_t  select;      
    uint16_t  reserved;
    char name[56];
};

#define fourcc_code(a, b, c, d) ((uint32_t)(a) | ((uint32_t)(b) << 8) | \
                                 ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))


#define DRM_FORMAT_RGB565       fourcc_code('R', 'G', '1', '6')
#define DRM_FORMAT_RGB888       fourcc_code('R', 'G', '2', '4') 
#define DRM_FORMAT_XRGB8888     fourcc_code('X', 'R', '2', '4') 

typedef struct {
    uint64_t fb_addr;
    uint32_t fb_width;
    uint32_t fb_height;
    uint32_t fb_bpp;

    uint32_t fb_stride;
    uint32_t fb_size;
} fb_info;

int KiSetupRamFB();
void KiSetupFramebuffer();
void KiWriteRGB256Pixel(fb_info *fb, uint16_t x, uint16_t y, uint8_t pixel[3]);
void KiCreateRGB(uint8_t* color, uint8_t r, uint8_t g, uint8_t b);
#endif