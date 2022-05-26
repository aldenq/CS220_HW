#pragma once
#include <stdint.h>

struct HashedString
{
    uint64_t startingIndex;
    uint16_t id;
    
    uint64_t length;
    uint8_t *hashedWords;
    uint16_t* matches;
};

uint64_t countWords(char *string);
struct HashedString *HashString_new(char *string);
void HashString_print(struct HashedString *source);