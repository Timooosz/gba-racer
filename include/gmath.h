#ifndef GMATH_H
#define GMATH_H

#include "types.h"

typedef int fixed;

#define FIX_SHIFT 8
#define FIX_SCALE (1 << FIX_SHIFT)

INLINE fixed TO_FIXED   (int x);
INLINE int   FROM_FIXED (fixed x);

fixed mul(fixed a, fixed b);
fixed div(fixed a, fixed b);

INLINE fixed sin(int x);
INLINE fixed cos(int x);

#endif // GMATH_H