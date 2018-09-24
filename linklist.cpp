#include "lib.h"
#include "stdlib.h"
#include "stdio.h"
#include "linklist.h"

void
linklist_insert(lknode** root, int k)
{
    lknode *tmp;
    lknode *x = new lknode;
    x->key = k;


    if ((*root) == NULL) {
        (*root) = x;
        x->next = NULL;

    }
    else
    {
        if ((*root)->next == NULL)
        {
            (*root)->next = x;
            x->next = NULL;
        }
        else
        {
            tmp = (*root);
            while(tmp->next != NULL)
                tmp = tmp->next;

            tmp->next = x;
            x->next = NULL;
        }
    }
}

void
linklist_debug(lknode* root)
{
    lknode* x = root;
    while (x != NULL)
    {
        printf("%d -> ", x->key);
        x = x->next;
    }
}
