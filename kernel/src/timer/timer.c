#include "timer.h"
#include "../drivers/mmio.h"



static volatile uint32_t *timermem = (uint32_t *) 0x09010000; 


uint32_t KiGetTimerValue() {
    return KiRead32(timermem);  
}

uint64_t KiGetCounterValue() {
    uint64_t value;
    asm volatile("mrs %0, cntvct_el0" : "=r" (value));
    return value;
}

uint64_t KiGetCounterFrequency() {
    uint64_t freq;
    asm volatile("mrs %0, cntfrq_el0" : "=r" (freq));
    return freq;
}

void KiSleep(uint32_t seconds) {
    uint32_t start_time = KiGetTimerValue();
    uint32_t target_time = start_time + seconds;
    while (KiGetTimerValue() < target_time) {
        continue;  
    }
}

void KiSleepMi(uint32_t milliseconds) {
    uint64_t start_time = KiGetCounterValue();
    uint64_t freq = KiGetCounterFrequency();  
    
    uint64_t target_ticks = (milliseconds * freq) / 1000;  
    uint64_t target_time = start_time + target_ticks;

    while (KiGetCounterValue() < target_time) {
        continue;  
    }
}