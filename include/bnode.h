#ifndef BNODE_H_INCLUDED
#define BNODE_H_INCLUDED

typedef struct btreenode
{
    int n;  // the number of key
    bool leaf;
    /* both key and child pointer need to be allocated according to the value **n** */
    struct btreenode **cp; // point to the child pointer
    void ** diskpage;
    char *key; // point to the key area

}bnode;

#endif // BNODE_H_INCLUDED
