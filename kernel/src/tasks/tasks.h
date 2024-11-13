#ifndef TASKS_H_INCLUDED
#define TASKS_H_INCLUDED





#include "../superheader.h"
#include <stdint.h>

#define MAX_TASKS 512

typedef struct _Task{
    uint8_t (*taskfunction)(); 
    uint16_t delay;
    uint16_t period;
    uint16_t latesttime;
    bool run;
    bool loop;
} Task;

void KiSystemTickHandler();
void XeCreateTask(uint16_t period, uint8_t (*taskfunction)());
void XeListTasks();

#endif