#include "drawing/drawing.h"
#include "drivers/ramfb/ramfb.h"
#include "drivers/uart/uart.h"
#include "kdebugshell/kserterm.h"
#include "timer/timer.h"
#include "tasks/tasks.h"
#include "drivers/ramfb/ramfb.h"
#include <stdint.h>
fb_info fb;

extern Task tasks[MAX_TASKS];
static uint8_t black[3] = {0, 0, 0};


uint8_t task1(){
    KiDrawRect(0, 0, HEIGHT, WIDTH, black);
    return 0;
}

uint8_t task4(){
    uint8_t rgb[3] = {0, 255, 255};
    KiDrawRect(700, 700, 200, 200, rgb);
    return 0;
}

uint8_t task2(){
    uint8_t rgb[3] = {255, 255, 0};
    KiDrawRect(400, 400, 9, 9, rgb);
    return 0;
}

uint8_t task3(){
    uint8_t rgb[3] = {0, 255, 255};
    KiDrawRect(100, 100, 200, 200, rgb);
    return 0;
}
void KiEntry(void) {
    // task 1 will always exist, it is what clears the screen
    tasks[1].period = 70;
    tasks[1].taskfunction = task1;
    tasks[1].run = true;
    tasks[1].loop = true;
    
    KiBeginKernelDebuggingShell();
    while(1){
        if(KiSerialGetCharNonWait() == 'X') KiBeginKernelDebuggingShell();
        KiSystemTickHandler();
        KiSleepMi(10);
    }
    while(1) continue;
}



