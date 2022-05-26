#include "plagiarismchecker.h"
#include "largeLUT.h"
#include "linkedlist.h"
#include "hashingstring.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
struct WordData *WordData_new(uint64_t index, struct HashedString *src)
{

    struct WordData *new = (struct WordData *)malloc(sizeof(struct WordData));
    new->index = index;
    new->src = src;

    return (new);
}

void hashedStringIntoLUT(struct HashedString *src, struct LUT *dst)
{
    struct WordData *prev;
    struct WordData *cur;
    for (int i = 0; i < src->length - 1; i++)
    {
        cur = WordData_new(i, src);
        uint16_t hash = (src->hashedWords[i] << 8) + src->hashedWords[i + 1];
        LUT_append(dst, hash, cur);

        if (i)
        {
            prev->next = hash;
        }
        else
        {
            src->startingIndex = hash;
        }
        prev = cur;
    }
}

void computeOverlap(struct LUT *src, uint64_t index)
{

    if (!src->table[index]->size)
    {
        return;
    }

    struct LinkNode *root = src->table[index]->root;
    struct LinkNode *current = root;

    // printf("seg %x   %d\n", root, index);
    // printf("stage 1 %d\n",index);
    while (current)
    {
        // printf("done1\n");
        // printf("%d  %x\n",src->table[index]->size, current->next);
        // printf("addr %x\n",((struct WordData *)current) );
        src->table[((struct WordData *)current->data)->next]->votes += 1;
        // printf("done2\n");

        current = current->next;
        
    }
    
    current = root;
    // printf("stage 2\n");
    while (current)
    {
        uint64_t votes = src->table[((struct WordData *)current->data)->next]->votes;
        uint16_t next = ((struct WordData *)current->data)->next;

        if (votes > 1)
        {
            // ((struct WordData *)current->data)->src->matches+=1;

            if (src->table[next]->voteSrcs == 0)
            {
                src->table[next]->voteSrcs = (void *)alloca(sizeof(void *) * votes);
                src->table[next]->voteIndex=0;
                for (int i = 0; i < votes; i++)
                {
                    src->table[next]->voteSrcs[i] = NULL;
                }
            }

            (src->table[next]->voteSrcs[src->table[((struct WordData *)current->data)->next]->voteIndex]) = ((struct WordData *)current->data)->src;
            src->table[next]->voteIndex += 1;
        }
        current = current->next;
    }

    current = root;
    // printf("stage 3\n");
    while (current)
    {

        uint64_t votes = src->table[((struct WordData *)current->data)->next]->votes;
        uint16_t next = ((struct WordData *)current->data)->next;

        if (votes > 1)
        {
            // ((struct WordData *)current->data)->src->matches+=1;

            if (src->table[next]->voteSrcs)
            {
                
                for (int i = 0; i < votes; i++)
                {
                    uint16_t matchIndex = ((struct HashedString *)src->table[next]->voteSrcs[i])->id;
                    if (((struct WordData *)current->data)->src->id != matchIndex){
                    ((struct WordData *)current->data)->src->matches[matchIndex] +=1;
                    }

                }
            }
        }

        // src->table[((struct WordData *)current->data)->next]->votes = 0;
        current = current->next;
    }
    // printf("stage 4\n");
    current = root;
    while (current)
    {
        // printf("seg0?\n");
        
        // uint64_t votes = src->table[((struct WordData *)current->data)->next]->votes;
        // printf("seg0.5?\n");
        uint16_t next = ((struct WordData *)current->data)->next;

        // printf("seg?\n");
        if (src->table[next]->votes != 0){
            src->table[next]->votes=0;
            src->table[next]->voteSrcs = 0;
            src->table[next]->voteIndex=0;
        }
        // printf("seg2?\n");
        // src->table[((struct WordData *)current->data)->next]->votes = 0;
        current = current->next;
    }

    // printf("stage 5\n");

}
