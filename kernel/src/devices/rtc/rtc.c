#include "rtc.h"
#include "../mmio.h"



uint64_t KiReturnTimeFromRealtimeClock(){
    return KiReadMemory64(0x09010000);
}
