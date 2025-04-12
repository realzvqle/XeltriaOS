#include "time.h"
#include "../devices/rtc/rtc.h"


// everything time related is here, this is a wrapper. You can use any way to get time
// by updating the KiGetSeconds, KiGetMilliseconds, and other functions here. As long as they
// are valid ways and accurate they won't break much


uint64_t KiGetSeconds(){
    return KiReturnTimeFromRealtimeClock();
}


void KiWait(uint32_t seconds){
    int prev = KiGetSeconds();
    while((KiGetSeconds() - prev) != seconds){
        continue;
    }    
}