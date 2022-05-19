#include <stdint.h>
#pragma once

struct Trie
{
    uint8_t lastIndex;
    uint32_t longest;

    uint64_t count;
    struct Trie *conns[26];
    char is_end;
    void *data;
};

/**
 * \brief constructor for Trie
 * \returns pointer to new trie
 */
struct Trie *Trie_new();

/**
 * 
 * \brief inserts a new word into the trie
 * \param dst pointer to root of trie
 * \param word pointer to null terminated string which will be inserted
 * \returns pointer to ending trie node
 * \warning does not return pointer to root of Trie!
 */
struct Trie *Trie_insert(struct Trie *dst, char *word);

/**
 * \brief tests if a word exists in the given trie, if it does it returns a pointer to the ending trie node for that word
 * \param dst pointer to root of trie
 * \param word pointer to null terminated string
 * \returns pointer to ending trie node for given word
 */
struct Trie *Trie_exists(struct Trie *dst, char *word);
