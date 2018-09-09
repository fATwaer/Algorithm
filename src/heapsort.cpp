#include "SortAlgorithm.h"
// push forward a element
inline int
PARENT(int i)
{
    return i / 2;
}

inline int
LEFT(int i)
{
    return i * 2;
}

inline int
RIGHT(int i)
{
    return i * 2 + 1;
}

inline void
pSwap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void
SortAlgorithm::maxHeapify(int i)
{
    int l = LEFT(i);
    int r = RIGHT(i);
    int lagest;

    if (l < arrayLength() && a[i-1] < a[l-1])
        lagest = l;
    else
        lagest = i;
    if (r < arrayLength() && a[lagest-1] < a[r-1])
        lagest = r;

    if (lagest != i) {
        pSwap(a[i-1], a[lagest -1]);
        maxHeapify(lagest);
    }

}
void
SortAlgorithm::bulidMaxHeap()
{
    for (int i = arrayLength()/2; i >= 1; i--)
    {
        outputArray();
        maxHeapify(i);
    }

}


void
SortAlgorithm::heapSort()
{
    for (int i = arrayLength(); i >= 2; i--) {
        pSwap(a[0], a[i-1]);
        maxHeapify(1);
        len--;

    }
    len = 9;
}






