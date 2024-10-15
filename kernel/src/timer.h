#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED





#include "superheader.h"


void KiSleep(uint32_t seconds);
uint32_t KiGetTimerValue();
uint64_t KiGetCounterValue();
uint64_t KiGetCounterFrequency();


#endif