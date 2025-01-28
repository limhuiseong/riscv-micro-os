#ifndef COMMON_H
#define COMMON_H

#define va_list  __builtin_va_list
#define va_start __builtin_va_start
#define va_end   __builtin_va_end
#define va_arg   __builtin_va_arg

#define true  1
#define false 0
#define NULL  ((void *) 0)

#define align_up(value, align)   __builtin_align_up(value, align)
#define is_aligned(value, align) __builtin_is_aligned(value, align)
#define offsetof(type, member)   __builtin_offsetof(type, member)

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef uint32_t size_t;
typedef int bool;
typedef uint32_t size_t;
typedef uint32_t paddr_t;
typedef uint32_t vaddr_t;

void *memset(void *buf, char c, size_t n);
void *memcpy(void *dst, const void *src, size_t n);

void putchar(char ch);
void printf(const char *fmt, ...);

#endif