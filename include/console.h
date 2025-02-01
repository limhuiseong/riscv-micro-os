///////////////////////////////////////////////////////////////////////////////
// ONLY USE FOR KERNEL
///////////////////////////////////////////////////////////////////////////////

#ifndef CONSOLE_H
#define CONSOLE_H

#define va_list __builtin_va_list
#define va_start __builtin_va_start
#define va_end __builtin_va_end
#define va_arg __builtin_va_arg

void putchar(char ch);
void printf(const char *fmt, ...);

#endif