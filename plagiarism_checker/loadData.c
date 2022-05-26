#include "loadData.h"
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

char *loadSampleFile(int value)
{
    char name[64];
    int index = sprintf(name, "./docs/alldocs/%d.txt", value);
    struct stat fileStats;

    name[index + 1] = 0;

    // printf("%s\n",name);

    FILE *fp = fopen(name, "r");
    // printf("addr %x\n", fp);

    // printf("n4 %x\n", fp);
    int fd = fileno(fp);
    // printf("n5\n");
    // printf("seg?\n");

    fstat(fd, &fileStats);
    // printf("size %d\n", fileStats.st_size);

    char *output = (char *)malloc(fileStats.st_size + 1);
    // fgets(output,fileStats.st_size, fp);
    for (int i = 0; i < fileStats.st_size; i++)
    {
        output[i] = fgetc(fp);
    }

    fclose(fp);

    output[fileStats.st_size] = 0;
    return (output);
}

void printstr(char *s)
{   
    char *curr = s;
    while (*curr)
    {

        printf("%c", *curr);
        curr += 1;
    }
    printf("\n");
}

// int main(){
//     char * test = loadSampleFile(3999);
//     printstr(test);
// }