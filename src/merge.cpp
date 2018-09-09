#include "SortAlgorithm.h"
#include <iostream>
using namespace std;

void
SortAlgorithm::mergeArray(int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    int i1, i2;

    for (int i = 0; i < n1; i++)
        L[i] = a[p+i];
    for (int i = 0; i < n2; i++)
        R[i] = a[q+i+1];

    i1 = 0;
    i2 = 0;
   // cout << "n :" << r - p + 1 << " " ;
    for (int k = p; k <= r; k++) {
        if ((L[i1] <= R[i2] && i1 < n1 )|| i2 == n2) {
            a[k] = L[i1];
            i1++;
        } else {
            a[k] = R[i2];
            i2++;
        }
        //cout << "k:" << k << " a[k] " << a[k] << " i1 " << i1 << " i2 " << i2 << " n "<< n1 << " n2 " << n2<< endl;
    }
}

void
SortAlgorithm::mergeSort(int p, int r)
{
    int q;

    if (p < r) {
        q = (r + p) / 2;

        mergeSort(p, q);
        mergeSort(q+1, r);
        //cout << p << " " << q << " " << r << endl;
        mergeArray(p, q, r);
        //outputArray();

    }
}
