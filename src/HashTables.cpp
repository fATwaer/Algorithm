#include "HashTables.h"
#include "lib.h"
#include "stdio.h"
HashTables::HashTables()
{
    //ctor
}

HashTables::~HashTables()
{
    //dtor
}

void
HashTables::debug()
{
    division_p = NULL;
    linklist_insert(&division_p, 10);
    linklist_insert(&division_p, 11);
    linklist_insert(&division_p, 12);
    printf("debug\n");
    linklist_debug(division_p);
}
