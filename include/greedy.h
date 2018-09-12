#ifndef GREEDY_H
#define GREEDY_H


class greedy
{
    public:
        /** Default constructor */
        greedy();
        /** Default destructor */
        virtual ~greedy();

    private:
};

#endif // GREEDY_H


class ActivitySelect
{
    public:
        ActivitySelect() = default;
        void recursive_selector();
        void iterative_selector();
    private:
        int s[11] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
        int f[11] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

};
