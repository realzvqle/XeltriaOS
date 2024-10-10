#include "timer.h"
#include "mmio.h"



static volatile uint32_t *timermem = (uint32_t *) 0x09010000; 


uint32_t KiGetTimerValue() {
    return KiRead32(timermem);  
}

void KiSleep(uint32_t seconds) {
    uint32_t start_time = KiGetTimerValue();
    uint32_t target_time = start_time + seconds;
    while (KiGetTimerValue() < target_time) {
        continue;  
    }
}