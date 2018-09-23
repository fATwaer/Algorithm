#ifndef FIB_H
#define FIB_H
#include "fibnode.h"


class FIB
{
    public:
        /** Default constructor */
        FIB();
        FIB(fibn* s, fibn* f): root(s), rear(f) {}
        /** Default destructor */
        virtual ~FIB();
        void Insert(int key);
        FIB& FIB_HeapUnion(FIB* h2);
        void debug();

        inline fibn* getRoot();
        inline fibn* getRear();
        inline fibn* getMin();

        inline void setMin(fibn* listmin);
        inline void setN(int N);
        inline int getN();

        int ExtractMin();
        void Consolidate();
        void DecreaseRoot();

    private:
        void FIB_CasecadingCut(fibn*);
        void FIB_Cut(fibn*, fibn*);
        void FIB_DecreaseKey(fibn*, int);
        void FIB_HeapInsert(fibn *x);
        void FIB_wlink(fibn* x);
        fibn* FIB_ExtractMin();
        void init_rootlist();
        fibn* FIB_plink(fibn* y, fibn* x);
        fibn* FIB_remove(fibn* y);


        fibn* heapmin;
        fibn* root;
        fibn* rear;
        int n;
};

inline fibn*
FIB::getRoot()
{
    return root;
}

inline fibn*
FIB::getMin()
{
    return heapmin;
}

inline fibn*
FIB::getRear()
{
    return rear;
}

inline void
FIB::setMin(fibn* lm)
{
    heapmin = lm;
}

inline void
FIB::setN(int N)
{
    this->n = N;
}

inline int
FIB::getN()
{
    return this->n;
}
#endif // FIB_H
