#include "terminal.h"
#include "drawing.h"
#include "ramfb.h"
#include "superheader.h"



static int line = 0;
static int line_cursor = 0;

static uint8_t white[3];
static uint8_t black[3];



void KiTerminalPrint(char* status) {
    static bool init = false;
    if(init == false){
        KiCreateRGB(black, 0, 0, 0);
        KiCreateRGB(white, 255, 255, 255);
        init = true;
    }
    if(!init){
       
        KiDrawRect(0, 10, HEIGHT - 10, WIDTH, black);
        init = true;
    }               
    
    KiDrawText(1 + line_cursor, 12 * line, status, 1, white);
    line_cursor += 5;
    line++;
    line_cursor = 0;
   
    if ((12 * line) >= HEIGHT) {
        KiDrawRect(0, 10, HEIGHT - 10, WIDTH, black);
        line = 0;
    } 
}



