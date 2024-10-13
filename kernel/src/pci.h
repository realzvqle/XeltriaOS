#ifndef PCI_H_INCLUDED
#define PCI_H_INCLUDED





#include "superheader.h"



uint16_t PCIConfigReadWord(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);

#endif