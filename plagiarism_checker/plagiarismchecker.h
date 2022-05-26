#pragma once
#include "hashingstring.h"
#include "largeLUT.h"

#include <stdint.h>

struct WordData
{
    uint64_t index;
    struct HashedString *src;
    uint64_t next;
    
};

void hashedStringIntoLUT(struct HashedString *src, struct LUT *dst);
struct WordData *WordData_new(uint64_t index, struct HashedString *src);

void computeOverlap(struct LUT *src, uint64_t index);
