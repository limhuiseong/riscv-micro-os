#ifndef PAGE_ALLOC_H
#define PAGE_ALLOC_H

#include "types.h"

#define PAGE_SIZE 4096

paddr_t alloc_pages(uint32_t n);

#endif