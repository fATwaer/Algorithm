#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
//#include "SortAlgorithm.h"
#include "huffmannode.h"
#include "linklist.h"

/*minimum heap*/
inline int _Parent(int i);
inline int _Left(int i);
inline int _Right(int i);
void minHeapify(int* a, int, int);
void buildHeap(int* , int len);
  /* for huffman*/
void minHeapify(hfnode* a, int, int);
void buildHeap(hfnode* , int len);
int extractmin(int*, int& len);
hfnode& extractmin(hfnode *, int& len);
void heapInsert(hfnode*, int&, hfnode&);

/*basic linklist*/
void linklist_insert(lknode**, int k);
void linklist_debug(lknode*);

template<typename T>
void
myswap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

#endif // LIB_H_INCLUDED
