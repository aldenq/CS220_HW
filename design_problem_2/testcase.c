#include "zombie.h"
//build command(linux x86_64): cc Tries.c zombie.c testcase.c -o test -Wall -pedantic
int main(){

    struct ZombieLookup *lookup = ZombieLookup_new();

   
    
    ZombieLookup_addZombie(lookup, Zombie_new("blocky zombie", "weakness:potion of weakness + golden apple or smite enchantment"));
    ZombieLookup_addZombie(lookup, Zombie_new("big zombie", "weakness: nuclear weapons"));
    ZombieLookup_addZombie(lookup, Zombie_new("small zombie", "weakness: big zombies"));
    ZombieLookup_addZombie(lookup, Zombie_new("fictional zombie", "weakness: change the plot"));


    printf("name:%s description:%s\n", "blocky zombie", ZombieLookup_lookup(lookup, "blocky zombie")->stringDesc);
    printf("name:%s description:%s\n", "small zombie", ZombieLookup_lookup(lookup, "small zombie")->stringDesc);
    printf("name:%s description:%s\n", "big zombie", ZombieLookup_lookup(lookup, "big zombie")->stringDesc);
    printf("name:%s description:%s\n", "fictional zombie", ZombieLookup_lookup(lookup, "fictional zombie")->stringDesc);
    
}