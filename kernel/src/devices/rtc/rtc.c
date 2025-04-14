#include "rtc.h"
#include "../memory.h"



uint64_t KiReturnTimeFromRealtimeClock(){
    return KiReadMemory64(0x09010000);
}
