/*
 * Console logging
 */

#include <stdio.h>

#include "defs.h"

static void
putx4(uint8_t n)
{
    n &= 0xf;
    if (n < 10) {
        putchar('0' + n);
    } else {
        putchar('a' + (n - 10));
    }
}

void
putx8(uint8_t x)
{
    putx4(x >> 4);
    putx4(x >> 0);    
}

void
putx16(uint16_t x)
{
    putx8(x >> 8);
    putx8(x >> 0);
}
