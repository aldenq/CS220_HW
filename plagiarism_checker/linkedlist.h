#pragma once
#include <stdint.h>
struct LinkNode
{
    struct LinkNode *next;
    void *data;
};

struct LinkNode *LinkNode_new(void *data);

struct LinkNode *LinkNode_append(struct LinkNode *root, void *data);

struct LinkNode *LinkNode_index(struct LinkNode *root, uint64_t index);

struct LinkNode *LinkNode_delete(struct LinkNode *root, uint64_t index);

struct LinkNode *LinkNode_insert(struct LinkNode *root, uint64_t index, void *data);

void LinkNode_print(struct LinkNode *root);
