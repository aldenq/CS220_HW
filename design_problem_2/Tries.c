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

    for (int i = 0; i < 128; i++)
    {
        new->conns[i] = 0;
    }
    return (new);
}

struct Trie *Trie_insert(struct Trie *dst, char *word)
{

    if (*word > 127){
        printf("invalid character in name\n");
        return(dst);
    }

    if (!*word) //not more letters in word
    {

        dst->count += 1;
        dst->is_end = 1;
        return dst;
    }

    if (dst->conns[*word ]) //branch exists
    {
        dst->count += 1;
        dst->lastIndex = *word ;
        return (Trie_insert(dst->conns[*word], word + 1));
    }
    else //branch does not exist
    {
        dst->count += 1;
        dst->lastIndex = *word;


        struct Trie *new = Trie_new();
        dst->conns[(*word)] = new;

        
        return (Trie_insert(new, word + 1));
    }
}
//i just borrowed and modified code from my other trie library so arguable "exists" is the wrong name to use now
struct Trie *Trie_exists(struct Trie *dst, char *word)
{
    if (word[1] == 0 && dst->conns[*word ]->is_end == 1)
    {
        return (dst->conns[*word ]);
    }

    if (dst->conns[*word ])
    {
        return (Trie_exists(dst->conns[*word], word + 1));
    }
    else
    {
        return (0);
    }
}
