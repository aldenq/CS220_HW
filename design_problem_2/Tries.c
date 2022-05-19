#include <stdlib.h>
#include "Tries.h"
#include <stdio.h>

struct Trie *Trie_new()
{
    struct Trie *new = (struct Trie *)malloc(sizeof(struct Trie));
    new->is_end = 0;
    new->count = 0;
    new->lastIndex = 0;
    new->longest = 0;

    for (int i = 0; i < 26; i++)
    {
        new->conns[i] = 0;
    }
    return (new);
}

struct Trie *Trie_insert(struct Trie *dst, char *word)
{

    // printf("c:%s\n", word);
    //printf("count2: %d\n",dst->count);

    if (!*word)
    {

        dst->count += 1;
        dst->is_end = 1;
        return dst;
    }

    if (dst->conns[*word - 'a']) //branch exists
    {
        // printf("exists\n");
        dst->count += 1;
        dst->lastIndex = *word - 'a';
        return (Trie_insert(dst->conns[*word - 'a'], word + 1));
    }
    else //branch does not exist
    {
        dst->count += 1;
        dst->lastIndex = *word - 'a';

        // printf("new\n");

        struct Trie *new = Trie_new();
        // printf("new:%llu\n",new);
        dst->conns[(*word) - 'a'] = new;

        // printf("writing to: %llx",dst->conns+*word);
        // printf("created0: %llx, char: %c\n",dst->conns[*word - 97],*word);
        return (Trie_insert(new, word + 1));
        // printf("created1: %llx, char: %c\n",dst->conns[*word - 97], *word);
    }
}

struct Trie *Trie_exists(struct Trie *dst, char *word)
{
    // printf("count: %d\n",dst->count);
    if (word[1] == 0 && dst->conns[*word - 97]->is_end == 1)
    {
        return (dst->conns[*word - 97]);
    }

    if (dst->conns[*word - 97])
    {
        return (Trie_exists(dst->conns[*word - 97], word + 1));
    }
    else
    {
        return (0);
    }
}
