#include "kserterm.h"
#include "../drivers/uart/uart.h"
#include "../runtimelib.h"
#include "../malloc.h"
#include "../sysintegrity/error.h"
#include "../timer/timer.h"
#include "../terminal/terminal.h"
#include "../rng.h"
#include "../drawing/drawing.h"
#include "../tasks/tasks.h"

char* cmds[] = {"echo", "ver", "exit", "printscr", "clearscr", "createtask", "pushback", "listask"};
bool exitshell = false;

extern uint16_t tasknum;
extern Task tasks[MAX_TASKS];

static inline uint8_t TaskTest(){
    int x = KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, WIDTH);
    int y = KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, HEIGHT);
    uint8_t color[3] = {KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), 
                        KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255), 
                        KiGenerateRandomValueWithinRange(KiGetCounterValue(), 0, 255)};
    KiDrawRect(x, y, 30, 30, color);
    return 0;
}

static inline void HandleCommands(char* cmd, char* args){
    int cmdsize = sizeof(cmds)/sizeof(cmds[0]);
    for(int i = 0; i < cmdsize; i++){
        if(RtlStringCompare(cmd, cmds[i]) == true){
            switch(i){
                case 0:
                    KiSerialPrint(args);
                    break;
                case 1:
                {
                    version ver = RtlGetCurrentVersion();
                    KiSerialPrint("XeltriaOS Build ");
                    KiSerialPrint(ver.type);
                    char buffer[512];
                    RtlIntegerToAscii(ver.kver, buffer);
                    KiSerialPrint("\nKERNEL VERSION: ");
                    KiSerialPrint(buffer);
                    RtlIntegerToAscii(ver.osver, buffer);
                    KiSerialPrint("\nSYSTEM VERSION: ");
                    KiSerialPrint(buffer);
                    break;
                }
                case 2:
                    exitshell = true;
                    break;
                case 3:
                    KiTerminalPrint(args);
                    break;
                case 4:
                    KiClearScreen();
                    break;
                case 5:
                {
                    char* periods = KiSerialGets("Period?", 1024);
                    int period = RtlAsciiToInteger(periods);
                    XeCreateTask(period, TaskTest);
                    KiFreeMemory(periods);
                    break;
            
                }
                case 6:
                {   
                    if(tasknum > 2){
                        if(tasknum != 2) tasknum--;
                        tasks[tasknum].run = false;
                    } 
                    else{
                        if(tasknum == 2){
                            if(tasks[tasknum].run == true){
                                tasks[tasknum].run = false;
                                break;
                            }
                        }
                        KiSerialPrint("Cannot Push Back, No Task Found\n");
                    } 
                    break;
                }
                case 7:
                    XeListTasks();
                    break;
                default:
                    KiPanic("SWITCH OVERRUN");
                    break;
            }
            return;
        }
    }
    KiSerialPrint("Command not Found\n");
}

void KiBeginKernelDebuggingShell(){ 
    KiSerialPrint("\nXeltriaOS Kernel Serial Debugger Shell\nDo SHIFT+P to Enter\n\n");
    while(exitshell == false){
        KiSleepMi(50);
        char* string = KiSerialGets("kdebug", 1024);
        char cmd[512];
        char args[512];
        RtlSliceStrings(string, ' ', cmd, args, 512, 512);
        HandleCommands(cmd, args);
        KiFreeMemory(string);
        KiSerialPutChar('\0');
    }
    exitshell = false;
    return;
}


