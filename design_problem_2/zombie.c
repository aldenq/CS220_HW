#include "Tries.h"
#include "zombie.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ZombieLookup *ZombieLookup_new()
{
    struct ZombieLookup *zombieLookup = (struct ZombieLookup *)malloc(sizeof(struct ZombieLookup *));
    zombieLookup->lookup = Trie_new();
    return (zombieLookup);
}

void ZombieLookup_addZombie(struct ZombieLookup *zombieLookup, struct Zombie *zombieData)
{
    struct Trie *final = Trie_insert(zombieLookup->lookup, zombieData->name);

    final->data = zombieData;
}

struct Zombie *ZombieLookup_lookup(struct ZombieLookup *zombieLookup, char *name)
{
    struct Trie *final = Trie_exists(zombieLookup->lookup, name);

    if (!final)
    {
        printf("Zombie:%s not found\n", name);
        return (0);
    }
    return (final->data);
}

struct Zombie *Zombie_new(char *name, char *descr)
{
    int nameLen = strlen(name);
    int descrLen = strlen(descr);

    struct Zombie *zdata = (struct Zombie *)malloc(sizeof(struct Zombie));

    zdata->name = (char *)malloc(nameLen);
    zdata->stringDesc = (char *)malloc(descrLen);

    strcpy(zdata->name, name);
    strcpy(zdata->stringDesc, descr);
    return (zdata);
}

// int main()
// {
//     struct ZombieData *myZombie = zombie_new("smellyzombie", "weakness: perfume");

//     struct ZombieData *myZombie2 = zombie_new("blockyzombie", "weakness: golden apple + potion of weakness or smite enchantment");
//     struct ZombieLookup *lookup = ZombieLookup_new();
//     ZombieLookup_addZombie(lookup, myZombie);

//     ZombieLookup_addZombie(lookup, myZombie2);

//     char *descr = ZombieLookup_lookup(lookup, "smellyzombie")->stringDesc;
//     printf("zombie: %s\n", descr);
//     descr = ZombieLookup_lookup(lookup, "blockyzombie")->stringDesc;
//     printf("zombie: %s\n", descr);
// }