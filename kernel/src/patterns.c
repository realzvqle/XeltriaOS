#include "patterns.h"
#include "drawing.h"
#include "ramfb.h"
#include "rng.h"
#include "superheader.h"
#include "timer.h"
#include "uart.h"
#include <stdint.h>




extern fb_info fb;

extern void KiHaltSystem();


void KiSpamPixels(){
    
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

void KiNoise(){
    uint8_t black[3] = {0, 0, 0};
    uint8_t white[3] = {255, 255, 255};
        
    for(;;){
        uint8_t color[3];
        if(KiGenerateRandomValue(KiGetCounterValue()) % 2 == 0) KiCreateRGB(color, 0, 0, 0);
        else KiCreateRGB(color, 255, 255, 255);

        KiWriteRGB256Pixel(&fb, KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, WIDTH),KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, HEIGHT), color);
        char result = KiSerialGetChar();
        if(result != NULL){
            uint8_t black[3] = { 0, 0, 0 };
            KiDrawRect(0, 0, HEIGHT, WIDTH, black);
            KiHaltSystem();
        }
    }
}

static inline uint32_t ohh(uint32_t n) {
    int idk = KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 10);
    return n + KiGenerateRandomValue(KiGetCounterValue()) % 10 ^+ (n << + idk & idk << idk);
}





void KiExtremeCRTThing(){
    for(;;){
        uint8_t color[3];
        KiCreateRGB(color, 255 >> KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), 255 >> KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), 255 << 1 << KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255));
        //KiCreateRGB(color, KiGenerateRandomValueWithinRange(KiGetCounterValue() - 100, 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue() - 10, 0, 255), KiGenerateRandomValueWithinRange(KiGetCounterValue() - 90, 0, 255));
        KiWriteRGB256Pixel(&fb, ohh(KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0 ^ KiGenerateRandomValue(KiGetCounterValue()), WIDTH)),
                                    ohh(KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, HEIGHT)), 
                                    color);
    }
}

//t*(90^80)-i^45