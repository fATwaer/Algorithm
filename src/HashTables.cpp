#include "HashTables.h"
#include "lib.h"
#include "stdio.h"
#include "memory.h"
#include "stdlib.h"

HashTables::HashTables()
{
    //ctor
    division_p = (linklistnode**) malloc(sizeof(linklistnode*[43]));
    memset(division_p, 0, m);
}

HashTables::~HashTables()
{
    //dtor
}



void
HashTables::Insert(int key)
{
    printf("insert %d\n", key);
    int h = hash_function(key);
   // printf("h: %d pointer %p: \n", h, (division_p[h]));
    linklist_insert(&(division_p[h]), key);
}


void
HashTables::debug()
{
    printf("debug\n");
    for (int i = 0; i < 43; i++)
    {
        printf("[%d]: ", i);
        linklist_debug(division_p[i]);
        printf("\n");
    }
}
