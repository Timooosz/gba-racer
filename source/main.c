#include "gba.h"

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

    while(1) {
        u16 timer_shifted = REG_TM2D >> 11; // >> 11 := 30 FPS
        if (timer_shifted != last_frame) {

            clear_screen(RGB15(5,5,5));

            // fps

            // DEBUG
            VRAM[30] = 0;
            VRAM[fps] = RGB15(0,31,0);

            // COUNT
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