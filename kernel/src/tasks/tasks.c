#include "tasks.h"
#include "../timer/timer.h"
#include "../kistdlib.h"
#include "../drivers/uart/uart.h"

Task tasks[MAX_TASKS];

uint64_t systick = 0;


static inline void PrintTaskResults(uint64_t elapsed_microseconds, int i){
    char buffer[512];
    char sbuffer[20];
    KiItoA(elapsed_microseconds, buffer);
    KiSerialPrint("\n----------------------------\n");
    KiSerialPrint("Time Spent On Task ");
    KiItoA(i, sbuffer);
    KiSerialPrint(sbuffer);
    KiSerialPrint(": ");
    KiSerialPrint(buffer);
    KiSerialPrint("\n----------------------------\n");
}

static void KiTaskSchedular() {
    for (int i = 0; i < MAX_TASKS; i++) {
        if(tasks[i].run != true) continue;
        if (tasks[i].period > 0) {
            if (tasks[i].delay == 0) {
                uint64_t start_time = KiGetCounterValue();
                tasks[i].taskfunction();
                uint64_t elapsed_microseconds = KiGetElapsedMicroseconds(start_time);
                PrintTaskResults(elapsed_microseconds, i);
                tasks[i].delay = tasks[i].period;
            } else {
                tasks[i].delay--;
            }
        }
    }
}


void KiSystemTickHandler(){
    systick++;
    KiTaskSchedular();
}