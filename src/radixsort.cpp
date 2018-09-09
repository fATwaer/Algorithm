#include "SortAlgorithm.h"
#include <iostream>
using namespace std;

int
getBase(int n)
{
    int d = 0;
    while (n/10 != 0)
        n /= 10, d++;
    return d;
}

int
power(int base,int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return base;

    int result = power(10, p/2);

    if (p % 2 == 1)
        return base * result * result;
    else
        return result * result;
}

int
getNumber(int n, int d)
{
    if (d == 0)
        return n % 10;
    return (n % power(10, d+1)) / power(10, d);
}


void
SortAlgorithm::dependInsertSort(int c[], int p, int q)
{
    int key;
    int temp;
    int j;

    for (int i = p + 1; i < q; i++) {
        key = c[i];
        temp = radixArr[i];
        j = i - 1;
        while (j >= 0 && c[j] > key) {
            pSwap(c[j], c[j+1]);
            pSwap(radixArr[j], radixArr[j+1]);
            j--;
        }
        c[j+1] = key;
        radixArr[j+1] = temp;

    }
}

void
SortAlgorithm::radixSort()
{
    int maxBase = 0;
    int d; //
    int b[arrayLength()];

    for (int i = 0; i < arrayLength(); i++) {
        d = getBase(radixArr[i]);
        maxBase = maxBase > d ? maxBase : d;
    }

    for (int j = 0; j < arrayLength(); j++) {
        cout << radixArr[j] << " ";
    }

    cout << endl;
    for (int i = 0; i < maxBase+1; i++) {
        for (int j = 0; j < arrayLength(); j++)
            b[j] = getNumber(radixArr[j], i);

        dependInsertSort(b, 0, arrayLength());


        for (int j = 0; j < arrayLength(); j++) {
            cout << radixArr[j] << " ";
        }
        cout << endl;


    }

}















