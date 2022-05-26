#include <stdint.h>
#include "hashingstring.h"
#include "linkedlist.h"
#include "largeLUT.h"
#include "plagiarismchecker.h"
#include "loadData.h"
#include <stdio.h>
#include <stdlib.h>
#define START_VALUE 2978
#define STOP_VALUE 4777
#define COUNT STOP_VALUE - START_VALUE + 1

int main()
{
    struct HashedString *mystr;

    struct LUT *myLut = LUT_new();

    struct HashedString *allStrings[COUNT];

    for (int i = START_VALUE; i <= STOP_VALUE; i++)
    {

        char *data = loadSampleFile(i);
        
        mystr = HashString_new(data);
        mystr->matches = (uint16_t *) malloc(sizeof(uint16_t) * COUNT);
        for (int j = 0; j < COUNT; j ++){
            mystr->matches[j]=0;

        }
        allStrings[i - START_VALUE] = mystr;
        // printf("%d\n",i-START_VALUE);

        mystr->id = i - START_VALUE;

        // printf("n2\n");
        hashedStringIntoLUT(mystr, myLut);
        // HashString_print(mystr);
    }
    // LUT_print(myLut);
    printf("done\n");
    for (int i = 0; i < 1<<16; i++)
    {
        computeOverlap(myLut, i);
    }



    uint16_t highestMatch = 0;
    uint16_t name=0;
    uint16_t pair=0;

    for (int i = 0; i < COUNT; i++)
    {
        uint16_t largest = 0;
        uint16_t largestIndex=0;

        for (int j = 0; j < COUNT; j ++){
            if (allStrings[i]->matches[j] > largest){
                largest = allStrings[i]->matches[j];
                largestIndex = j;
            }
        }


        if (largest > highestMatch){
            highestMatch=largest;
            name = i + START_VALUE;
            pair = largestIndex + START_VALUE;
        }

        
        double strength = (double)largest/(double)allStrings[i]->length;
        if (strength > 1){
        printf("name:%d pair:%d level:%.6f\n", i + START_VALUE, largestIndex + START_VALUE, strength);
        }


        
        
    }

    // printf("highest: name%d  pair:%d  level%d\n", name, pair, highestMatch);


    // char * data = loadSampleFile(3999);
    

    // LUT_print(myLut);
}