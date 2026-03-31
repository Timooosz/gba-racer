#ifndef INPUT_H
#define INPUT_H

#include "types.h"

#define KEY_STATE (*(volatile u16*)0x04000130)

#define KEY_A          !(KEY_STATE & 1)
#define KEY_B          !(KEY_STATE & 2)
#define KEY_SELECT     !(KEY_STATE & 4)
#define KEY_START      !(KEY_STATE & 8)
#define KEY_R          !(KEY_STATE & 16)
#define KEY_L          !(KEY_STATE & 32)
#define KEY_DPAD_UP    !(KEY_STATE & 64)
#define KEY_DPAD_DOWN  !(KEY_STATE & 128)
#define KEY_DPAD_RIGHT !(KEY_STATE & 256)
#define KEY_DPAD_LEFT  !(KEY_STATE & 512)

#endif // INPUT_H