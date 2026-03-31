#ifndef GMATH_H
#define GMATH_H

#include "types.h"

typedef int fixed;

#define FIX_SHIFT 8
#define FIX_SCALE (1 << FIX_SHIFT)

INLINE fixed TO_FIXED(int x)     {return (x << FIX_SHIFT);}
INLINE int   FROM_FIXED(fixed x) {return (x >> FIX_SHIFT);}

fixed mul(fixed a, fixed b);
fixed div(fixed a, fixed b);

extern const short sin_lut[256];

INLINE fixed f_sin(int x) {return sin_lut[x & 0xFF];}
INLINE fixed f_cos(int x) {return sin_lut[(x + 64) & 0xFF];}

#endif // GMATH_H