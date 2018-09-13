#ifndef HUFFMANNODE_H_INCLUDED
#define HUFFMANNODE_H_INCLUDED



typedef struct huffmantree{
    huffmantree() = default;
    huffmantree(char c, int f) : freq(f), character(c){}
    int freq;
    char character;
    struct huffmantree *left;
    struct huffmantree *right;


}hfnode;


#endif // HUFFMANNODE_H_INCLUDED
