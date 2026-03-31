#ifndef VIDEO_H
#define VIDEO_H

#include "types.h"

u16* VRAM;

#define VRAM_FRONT_BUFFER (u16*)0x06000000
#define VRAM_BACK_BUFFER  (u16*)0x0600A000

#define BACK_BUFFER 0x10
volatile u16* scanline = (volatile u16*)0x04000006;

#define MODE5    0x0005
#define DCNT_BG2 0x0400

#define GBA_SCREEN_WIDTH  160
#define GBA_SCREEN_HEIGHT 128

#define GAME_SCREEN_WIDTH  120
#define GAME_SCREEN_HEIGHT 80

#define RGB15(r,g,b) ((r) + ((g)<<5) + ((b)<<10))

// Scaling Mode 5 Screen

#define REG_BG2PA *(volatile u16*)0x04000020
#define REG_BG2PD *(volatile u16*)0x04000026

#endif // VIDEO_H