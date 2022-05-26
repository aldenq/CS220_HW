#include <stdint.h>
#include "hashingstring.h"
#include <stdlib.h>
#include <stdio.h>

uint64_t countWords(char *string)
{
    if (!*string || !*(string + 1))
    {
        return (0);
    }

    char *current = string + 1;
    uint64_t wordCount = 0;

    while (*current)
    {

        wordCount += *current == ' ' && *(current - 1) != ' ';

        current += 1;
    }
    wordCount += *(current - 1) != ' ';

    return (wordCount);
}

struct HashedString *HashString_new(char *string)
{
    uint64_t wordCount = countWords(string);
    // printf("word count %d\n", wordCount);
    struct HashedString *hashedString = (struct HashedString *)malloc(sizeof(struct HashedString));
    hashedString->hashedWords = (uint8_t *)malloc(wordCount);
    hashedString->length = wordCount;
    hashedString->matches = 0;

    //current hashing algorithm is just summing all characters in the word

    char *current = string;
    uint8_t sum = 0;
    uint64_t index = 0;

    while (*current)
    {

        if (*current != ' ')
        {
            sum += *current;
        }
        else
        {
            if (sum > 0)
            {
                hashedString->hashedWords[index] = sum;
                index += 1;
                sum = 0;
            }
        }
        current += 1;
    }

    hashedString->hashedWords[index] = sum;

    return (hashedString);
}

void HashString_print(struct HashedString *source)
{
    for (int i = 0; i < source->length; i++)
    {
        printf("%d ", source->hashedWords[i]);
    }
    printf("\n");
}