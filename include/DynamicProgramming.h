#ifndef DYNAMICPROGRAMMING_H
#define DYNAMICPROGRAMMING_H
#include <string>
using namespace std;

enum direction {
    LEFT = 0,
    UP,
    UpperLeft
};

class DynamicProgramming
{
    public:
        /** Default constructor */
        DynamicProgramming();
        /** Default destructor */
        virtual ~DynamicProgramming();

        /** longest common substring */
        DynamicProgramming(string s1, string s2) : strA(s1), strB(s2), lcs("") {}
        void DebugPrint1();
        void LCSlength();

    private:
        /** longest common substring */
        string strA;
        string strB;
        string lcs;
};

#endif // DYNAMICPROGRAMMING_H
