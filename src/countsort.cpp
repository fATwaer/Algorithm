#include "SortAlgorithm.h"


void
SortAlgorithm::countSort()
{
    // the size fo array c must
    // bigger than the maximum number
    // in the array a.
    int length = arrayLength();
    int b[length], c[length];

    for (int i = 0; i < length; i++) {
        c[i] = 0;
        b[i] = 0;
    }
    for (int i = 1; i <= length; i++)
        c[a[i-1]]++;
    for (int i = 1; i < length; i++)
        c[i] = c[i-1] + c[i];

    for (int i = length; i >= 1; i--) {
        b[c[a[i-1]]-1] = a[i-1];
        c[a[i-1]]--;

    }
    for (int i = 0; i < length; i++)
        a[i] = b[i];

}
