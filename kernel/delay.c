#include "delay.h"

void delay(int cycle)
{
    if (cycle <= 0)
        cycle = 30000000;
    for (int i = 0; i < cycle; i++)
        __asm__ __volatile__("nop");
}