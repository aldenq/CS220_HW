#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
struct LinkNode *LinkNode_new(void *data)
{
    struct LinkNode *new = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    new->data = data;
    new->next = 0;
    return (new);
}

struct LinkNode *LinkNode_append(struct LinkNode *root, void *data)
{

    if (!root)
    {

        return (LinkNode_new(data));
    }

    struct LinkNode *current = root;
    while (current->next)
    {
        current = current->next;
    }

    current->next = LinkNode_new(data);
    return (root);
}

struct LinkNode *LinkNode_index(struct LinkNode *root, uint64_t index)
{

    struct LinkNode *current = root;

    uint64_t currentIndex = 0;

    while (currentIndex != index)
    {
        if (!current->next)
        {
            return (0);
        }

        current = current->next;
        currentIndex += 1;
    }
    return (current);
}

struct LinkNode *LinkNode_delete(struct LinkNode *root, uint64_t index)
{
    struct LinkNode *returnVal = root;

    if (index == 0)
    {
        returnVal = root->next;
        free(root);
        return (returnVal);
    }

    struct LinkNode *prevNode = LinkNode_index(root, index - 1);

    if (prevNode->next == 0)
    {
        return (0);
    }

    struct LinkNode *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    free(temp);

    return (returnVal);
}

struct LinkNode *LinkNode_insert(struct LinkNode *root, uint64_t index, void *data)
{

    struct LinkNode *new = LinkNode_new(data);

    if (index == 0)
    {
        new->next = root;
        return (new);
    }

    struct LinkNode *prevNode = LinkNode_index(root, index - 1);
    new->next = prevNode->next;
    prevNode->next = new;
    return (root);
}

void LinkNode_print(struct LinkNode *root)
{
    while (root)
    {
        printf("%X ", root->data);
        root = root->next;
    }
}

// int main(){
//     struct LinkNode * myll = LinkNode_new(10);

//     myll = LinkNode_append(myll, 45);
//     myll = LinkNode_append(myll, 64);
//     myll = LinkNode_append(myll, 128);
//     myll = LinkNode_delete(myll, 2);
//     myll = LinkNode_insert(myll, 1, 15);
//     LinkNode_print(myll);
// }
