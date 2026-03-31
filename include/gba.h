#ifndef GBA_H
#define GBA_H

#include "types.h"
#include "input.h"
#include "video.h"

#define DISPCNT  *(u32*)0x04000000 // Display Settings Register

#define TIMER_ENABLE   *(u16*)0x0400010A
#define TIMER_OVERFLOW *(u16*)0x0400010E
#define REG_TM2D       *(volatile u16*)0x04000108 // FPS Timer

#define IN_IWRAM __attribute__ ((section (".iwram"))) // Fast IWRAM (32KB)
#define IN_EWRAM __attribute__ ((section (".ewram"))) // Fast EWRAM (256KB)

#endif // GBA_H