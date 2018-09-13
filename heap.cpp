#include "lib.h"
#include "stdio.h"
#include "greedy.h"
inline int _Parent(int i)
{
    return i / 2;
}
inline int _Left(int i)
{
    return i * 2;
}

inline int _Right(int i)
{
    return i * 2 + 1;
}


/*sort from 1 to len*/
void
minHeapify(int* a, int len, int i)
{
    int r = _Right(i);
    int l = _Left(i) ;
    int minimum;

    if (l < len && a[l-1] < a[i-1])
        minimum = l;
    else
        minimum = i;

    if (r < len && a[r-1] < a[minimum-1])
        minimum = r;
    //printf("r[%d] %d, l[%d] %d, min %d\n", r-1, a[r-1], l-1, a[l-1], minimum);
    if (minimum != i) {
        myswap(a[minimum-1], a[i-1]);

        minHeapify(a, len, minimum);
    }
}



void
buildHeap(int* a, int len)
{
    for (int i = len/2; i >= 1; i--)
        minHeapify(a, len, i);
}





int
extractmin(int* heap, int &len)
{
    myswap(heap[0], heap[len-1]);
    len--;
    minHeapify(heap, len, 1);
    return heap[len];
}

void
minHeapify(hfnode* a, int len, int i)
{
    int r = _Right(i);
    int l = _Left(i) ;
    int minimum;

    if (l < len && a[l-1].freq < a[i-1].freq)
        minimum = l;
    else
        minimum = i;

    if (r < len && a[r-1].freq < a[minimum-1].freq)
        minimum = r;

    if (minimum != i) {
        myswap(a[minimum-1], a[i-1]);

        minHeapify(a, len, minimum);
    }
}

void
buildHeap(hfnode* a, int len)
{

    for (int i = len/2; i >= 1; i--)
        minHeapify(a, len, i);
}


hfnode&
extractmin(hfnode* heap, int &len)
{
    myswap(heap[0], heap[len-1]);
    len--;
    minHeapify(heap, len, 1);
    return heap[len];
}

void
heapInsert(hfnode* heap, int &len, hfnode& z)
{
    heap[len++] = z;
    buildHeap(heap, len+1);
}
