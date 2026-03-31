#include "gba.h"

#define HALF_GAME_SCREEN_WIDTH  GAME_SCREEN_WIDTH / 2
#define HALF_GAME_SCREEN_HEIGHT GAME_SCREEN_HEIGHT / 2

int last_frame = 0, fps = 0;

void clear_screen(u16 color) {
    for (int x = 0; x < GAME_SCREEN_WIDTH; x++) {
        for (int y = 0; y < GAME_SCREEN_HEIGHT; y++) {
            VRAM[y * GBA_SCREEN_WIDTH + x] = color;
        }
    }
}

int main() {
    // Use Mode 5 with BG2 enabled
    DISPCNT = MODE5 | DCNT_BG2;
    // Setup Timer
    TIMER_ENABLE = 0x82;
    TIMER_OVERFLOW = 0x84;
    //Scale Screen
    REG_BG2PA = 256 / 2; // 256: Original Scale
    REG_BG2PD = 256 / 2;

    int count = 0;
    fixed x, y;

    while(1) {
        u16 timer_shifted = REG_TM2D >> 11; // >> 11 := 30 FPS
        if (timer_shifted != last_frame) {

            clear_screen(RGB15(2,2,2));

            x = TO_FIXED(HALF_GAME_SCREEN_WIDTH);
            x += mul(TO_FIXED(20), f_sin(count));
            x = FROM_FIXED(x);

            y = TO_FIXED(HALF_GAME_SCREEN_HEIGHT);
            y += mul(TO_FIXED(20), f_cos(count++));
            y = FROM_FIXED(y);

            VRAM[y * GBA_SCREEN_WIDTH + x] = RGB15(31,0,0);

            // count frames

            fps += 1;
            if (last_frame > timer_shifted) fps = 0;
            last_frame = timer_shifted;

            // Swap buffers once all scanlines drawn

            while (*scanline<160);
            if (DISPCNT & BACK_BUFFER) { // Switch to back buffer
                DISPCNT &= ~BACK_BUFFER;
                VRAM = (u16*)VRAM_BACK_BUFFER;
            } else {
                DISPCNT |= BACK_BUFFER;
                VRAM = (u16*)VRAM_FRONT_BUFFER;
            }
        }
    }
}