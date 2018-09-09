#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H


class SortAlgorithm
{
    public:
        SortAlgorithm() = default;
        virtual ~SortAlgorithm();
        void insertSort(int a[], int be, int len);
        void outputArray();
        int arrayLength();
        void mergeSort(int p, int r);
        void heapSort();
        void bulidMaxHeap();
        int partitionArray(int p, int r);
        void quickSort(int p, int r);
        void countSort();
        void dependInsertSort(int c[], int p, int q);
        void radixSort();

    private:
        void mergeArray(int p, int q, int r);
        void maxHeapify(int i);

        int len = 9;
        int a[9] = {6, 5, 7, 3, 2, 8, 0, 4, 1};
        int olen = 9;
        int radixArr[9] = {777, 345, 222, 355, 267, 789, 210, 10, 994};


};

inline void pSwap(int &, int &);
int power(int, int);

#endif // SORTALGORITHM_H
