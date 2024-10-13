#include "pci.h"
#include "mmio.h"
#include "terminal.h"


static volatile uint32_t *pci = (uint32_t *) 0x801000000;

uint16_t PCIConfigReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset){
    uint32_t address;
    uint32_t lbus  = (uint32_t)bus;
    uint32_t lslot = (uint32_t)slot;
    uint32_t lfunc = (uint32_t)func;
    uint32_t data;
    uint16_t tmp = 0;
    address = (uint32_t)((lbus << 16) | (lslot << 11) |
              (lfunc << 8) | (offset & 0xFC) | ((uint32_t)0x80000000));
    
    KiTerminalPrint("Hi :3");
    data = KiRead32(pci);
    KiTerminalPrint("Bye :3");

    tmp = (uint16_t)(data >> ((offset & 2) * 8)) & 0xFFFF;
    return tmp;
}