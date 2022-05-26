#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "largeLUT.h"

struct LUTEntry *LUTEntry_new()
{
    struct LUTEntry *new = (struct LUTEntry *)malloc(sizeof(struct LUTEntry));
    new->size = 0;
    new->root = 0;
    new->votes = 0;
    new->voteSrcs=0;
    new->voteIndex=0;
    return (new);
}

void LUTEntry_append(struct LUTEntry *base, void *data)
{
    
    // printf("e2 %X\n", base);
    struct LinkNode *root = LinkNode_append(base->root, data);
    if (base->size == 0){
        base->root=root;
    }
    base->size += 1;
}

struct LUT *LUT_new()
{
    struct LUT *new = (struct LUT *)malloc(sizeof(struct LUT));
    for (int i = 0; i < 1 << 16; i++)
    {
        new->table[i] = LUTEntry_new();
    }
    return (new);
}

void LUT_append(struct LUT *lut, uint16_t hash, void *data)
{

    LUTEntry_append(lut->table[hash], data);
}

void LUT_print(struct LUT *lut)
{
    for (int i = 0; i < 1 << 16; i++)
    {
        printf("%d ", lut->table[i]->size);
    }
    printf("\n");
}
