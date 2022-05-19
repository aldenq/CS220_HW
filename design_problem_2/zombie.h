#include "Tries.h"
#pragma once
/**
 * \brief effectivly just a typedef for a Trie, used to store/lookup zombies
 * 
 */ 
struct ZombieLookup
{
    struct Trie *lookup;
};


/**
 * \brief used to store names and descriptions of zombies
 * 
 */ 
struct Zombie
{
    char *name;
    char *stringDesc;
};

/**
 * \brief 'constructor' for ZombieLookup 
 * \returns pointer to new ZombieLookup
 */
struct ZombieLookup *ZombieLookup_new();

/**
 * \brief takes in zombie data and adds it into the zombielookup so it can be searched later
 * \param zombieLookup pointer to zombielookup which the new zombie should be added to
 * \param zombieData pointer to zombiedata which should be inserted 
 */
void ZombieLookup_addZombie(struct ZombieLookup *zombieLookup, struct Zombie *zombieData);

/**
 * \brief given a zombie name the returns the data for that zombie
 * \warning will return a null pointer if the zombie is not found
 * \param zombieLookup pointer to ZombieLookup which should be searched with the given name
 * \param name name of zombie which informated is requested for
 * \returns pointer to a zombieData struct which contains data on the requested zombie
 */
struct Zombie *ZombieLookup_lookup(struct ZombieLookup *zombieLookup, char *name);

/**
 * \brief creates a new zombie/ 'constructor' for ZombieData
 * \param name name of zombie (null terminated string)
 * \param descr description of zombie (null terminated string)
 * \returns pointer to the new zombieData
 * \warning names must be only standard (non extended) ascii values
 */
struct Zombie *Zombie_new(char *name, char *descr);
