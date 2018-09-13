#ifndef GREEDY_H
#define GREEDY_H
#include <vector>
using namespace std;
#include "huffmannode.h"

class greedy
{
    public:
        /** Default constructor */
        greedy();
        /** Default destructor */
        virtual ~greedy();

    private:
};



class ActivitySelect
{
    public:
        ActivitySelect() = default;
        void recursive_selector(int, int);
        void iterative_selector(int);
        void debug();
        int * getarray();
    private:
        int s[12] = {0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
        int f[12] = {0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
        vector<int> greedy_sequence;


};

class Huffmantranslations
{
    public:
        Huffmantranslations() = default;
        void heapify(hfnode arr[], int len);
        hfnode* buildHuffmanTree(hfnode arr[], int len);


    private:
        int len;
};


#endif // GREEDY_H
