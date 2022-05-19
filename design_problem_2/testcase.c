#include "zombie.h"
//build command(linux x86_64): cc Tries.c zombie.c testcase.c -o test -Wall -pedantic
int main(){

    struct ZombieLookup *lookup = ZombieLookup_new();

   
    
    ZombieLookup_addZombie(lookup, zombie_new("blockyzombie", "weakness:potion of weakness + golden apple or smite enchantment"));
    ZombieLookup_addZombie(lookup, zombie_new("bigzombie", "weakness: nuclear weapons"));
    ZombieLookup_addZombie(lookup, zombie_new("smallzombie", "weakness: big zombies"));
    ZombieLookup_addZombie(lookup, zombie_new("fictionalzombie", "weakness: change the plot"));


    printf("name:%s description:%s\n", "blockyzombie", ZombieLookup_lookup(lookup, "blockyzombie")->stringDesc);
    printf("name:%s description:%s\n", "smallzombie", ZombieLookup_lookup(lookup, "smallzombie")->stringDesc);
    printf("name:%s description:%s\n", "bigzombie", ZombieLookup_lookup(lookup, "bigzombie")->stringDesc);
    printf("name:%s description:%s\n", "fictionalzombie", ZombieLookup_lookup(lookup, "fictionalzombie")->stringDesc);
    
}