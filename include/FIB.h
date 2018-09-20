#ifndef FIB_H
#define FIB_H
#include "fibnode.h"


class FIB
{
    public:
        /** Default constructor */
        FIB();
        /** Default destructor */
        virtual ~FIB();
        void Insert(int key);


    private:
        void FIB_HeapInsert(fibn *x);
        void FIB_link(fibn* x);

        fibn* heapmin;
        fibn* root;
        int n;
};

#endif // FIB_H
