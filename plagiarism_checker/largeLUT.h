#pragma once
#include <stdint.h>
#include "linkedlist.h"

struct LUTEntry
{
    uint64_t size;
    struct LinkNode *root;
    uint64_t votes;
    void ** voteSrcs;
    uint16_t voteIndex;
    
};

struct LUT
{
    struct LUTEntry *table[1 << 16];
};

struct LUTEntry *LUTEntry_new();
void LUTEntry_append(struct LUTEntry *base, void *data);

struct LUT *LUT_new();
void LUT_append(struct LUT *lut, uint16_t hash, void *data);
void LUT_print(struct LUT *lut);
