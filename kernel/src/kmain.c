#include "drawing.h"
#include "ramfb.h"


fb_info fb;

void KiEntry(void) {
    
    
    uint8_t color[3];
    KiCreateRGB(color, 255, 60, 90);
    KiDrawRect(10, 10, 100, 100, color);
    while(1) continue;
}



