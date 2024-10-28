#include "kserterm.h"
#include "../drivers/uart/uart.h"
#include "../kistdlib.h"
#include "../malloc.h"
#include "../sysintegrity/error.h"
#include "../timer/timer.h"



char* cmds[] = {"echo", "ver", "exit"};
bool exitshell = false;

static inline void HandleCommands(char* cmd, char* args){
    int cmdsize = sizeof(cmds)/sizeof(cmds[0]);
    for(int i = 0; i < cmdsize; i++){
        if(KiStringCompare(cmd, cmds[i]) == true){
            switch(i){
                case 0:
                    KiSerialPrint(args);
                    break;
                case 1:
                {
                    version ver = KiGetCurrentVersion();
                    KiSerialPrint("XeltriaOS Build ");
                    KiSerialPrint(ver.type);
                    char buffer[512];
                    KiItoA(ver.kver, buffer);
                    KiSerialPrint("\nKERNEL VERSION: ");
                    KiSerialPrint(buffer);
                    KiItoA(ver.osver, buffer);
                    KiSerialPrint("\nSYSTEM VERSION: ");
                    KiSerialPrint(buffer);
                    break;
                }
                case 2:
                    exitshell = true;
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
        KiSliceStrings(string, ' ', cmd, args, 512, 512);
        HandleCommands(cmd, args);
        KiFreeMemory(string);
        KiSerialPutChar('\0');
    }
}


