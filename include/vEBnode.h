#ifndef VEBNODE_H_INCLUDED
#define VEBNODE_H_INCLUDED
#include "math.h"
#include "stdlib.h"

typedef struct vanEmdeBoasNode {
    vanEmdeBoasNode();
    vanEmdeBoasNode(int universe) : u(universe) , summary(NULL), maximum(-1), minimum(-1) {
        int sqrt_u = int(sqrt(u));

        if (universe != 2) {
            cluster = (struct vanEmdeBoasNode**)malloc(sizeof(struct vanEmdeBoasNode*[sqrt_u]));
            for (int i = 0; i < sqrt_u; i++)
                cluster[i] = NULL;
        } else {
            cluster = NULL;
        }
    }
    int u;
    int maximum;
    int minimum;

    struct vanEmdeBoasNode** cluster;
    struct vanEmdeBoasNode* summary;

}vEBnode;

#endif // VEBNODE_H_INCLUDED
