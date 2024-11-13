#include "tasks.h"
#include "../timer/timer.h"
#include "../runtimelib.h"
#include "../drivers/uart/uart.h"

Task tasks[MAX_TASKS];
uint16_t tasknum = 2;
uint64_t systick = 0;


static inline void PrintTaskResults(uint64_t elapsed_microseconds, int i){
    char buffer[512];
    char sbuffer[20];
    RtlIntegerToAscii(elapsed_microseconds, buffer);
    KiSerialPrint("\n----------------------------\n");
    KiSerialPrint("Time Spent On Task ");
    RtlIntegerToAscii(i, sbuffer);
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
                uint8_t result = tasks[i].taskfunction();
                uint64_t elapsed_microseconds = KiGetElapsedMicroseconds(start_time);
                PrintTaskResults(elapsed_microseconds, i);
                tasks[i].delay = tasks[i].period;
                if(result == 1) tasks[i].run = false;
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

void XeCreateTask(uint16_t period, uint8_t (*taskfunction)()){
    if(tasknum >= MAX_TASKS - 1){
        KiSerialPrint("Task Array is Full, Delete a Task to make a new one\n");
        return;
    } 
    tasks[tasknum].taskfunction = taskfunction;
    tasks[tasknum].period = period;
    tasks[tasknum].run = true;
    tasknum++;
}