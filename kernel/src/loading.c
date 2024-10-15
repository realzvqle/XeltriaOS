#include "loading.h"
#include "drawing.h"
#include "ramfb.h"
#include "rng.h"
#include "superheader.h"
#include "timer.h"
#include "uart.h"




extern fb_info fb;

extern void KiHaltSystem();


void KiDrawLoadingScreen(){
    
    for(;;){
        uint8_t color[3];
        KiCreateRGB(color, KiGenerateRandomValueWithinRange(KiGetCounterValue() - 100, 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue() - 10, 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue() - 90, 0, 255));
        KiWriteRGB256Pixel(&fb, KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, WIDTH),KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, HEIGHT), color);
        char result = KiSerialGetChar();
        if(result != NULL){
            uint8_t black[3] = { 0, 0, 0 };
            KiDrawRect(0, 0, HEIGHT, WIDTH, black);
            KiHaltSystem();
        }
    }
}