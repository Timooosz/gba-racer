/*
gcc tools/lut_gen.c -o tools/lut_gen && tools/lut_gen
*/

#include <stdio.h>
#include <math.h>

#define SIZE 256
#define FIX_SHIFT 8

#define PER_ROW 8

#define PI 3.1415926535

int main() {
    printf("const short sin_lut[%d] = {\n\t", SIZE);

    for (int i = 0; i < SIZE; i++) {
        double angle = (2.0 * PI * i) / SIZE;
        int value = (int)(sin(angle) * (1 << FIX_SHIFT));
        printf("%d, ", value);

        if (i % PER_ROW == PER_ROW - 1) printf("\n\t");
    }

    printf("};\n");
    return 0;
}