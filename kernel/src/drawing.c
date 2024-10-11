#include "drawing.h"
#include "ramfb.h"




extern fb_info fb;





void KiDrawRect(int x, int y, int height, int width, uint8_t color[3]){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            KiWriteRGB256Pixel(&fb, x + j, y + i, color);
        }
    }
}
