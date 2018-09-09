#include "SortAlgorithm.h"

int
SortAlgorithm::partitionArray(int p, int r)
{
    int key = a[r-1];
    int i = p - 1;

    for (int k = p; k <= r; k++) {
        if (a[k-1] < key) {
            i++;
            pSwap(a[i-1], a[k-1]);
        }
    }
    pSwap(a[i+1-1], a[r-1]);
    return i+1;
}

void
SortAlgorithm::quickSort(int p, int r)
{
    if (p < r) {
        int q = partitionArray(p, r);
        quickSort(p, q-1);
        quickSort(q+1, r);
    }
}



