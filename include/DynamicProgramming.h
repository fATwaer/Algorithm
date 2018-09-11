#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

enum direction {
    LEFT = 0,
    UP = 1,
    UpperLeft = 2
};

class DynamicProgramming
{

    public:
        /** Default constructor */
        DynamicProgramming();
        /** Default destructor */
        virtual ~DynamicProgramming();

        /** longest common substring */
        DynamicProgramming(string s1, string s2) : strA(s1), strB(s2), lcs("") , m(strA.length()+1), n(strB.length()+1){}
        void DebugPrint1();
        void LCSlengthIterate();
        void PrintLCS(direction **b, int **c, int x, int y);

    private:
        /** longest common substring */
        string strA;
        string strB;
        string lcs;
        int m,n;

};

#endif // DYNAMICPROGRAMMING_H
