#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <iomanip>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <string>
# include <climits>
# include <cerrno>

typedef std::deque<int> deque;
typedef deque::iterator dIterator;
typedef std::vector<int> vector;
typedef vector::iterator vIterator;

class PmergeMe
{
    private:
        vector vec;
        deque deq;

        int jacobsthalIndex;
        int jacobsthalNum[30];
        int numOfInsert;

    public:
        PmergeMe();
        PmergeMe(PmergeMe const &rhs);
        PmergeMe &operator=(PmergeMe const &rhs);
        ~PmergeMe();
        
        void    input(int ac, char **av);
        bool    validInput(char **av);
        bool    validNumber(char **av);
        void    printOutput(int ac, char **av, double vecT,double deqT);
        void    setJacobsthalNum();
        int     getNextIndex(int index);

        double  vecTime();
        void    vecMergeInsert(int numOfElement, int sizeOfElement);
        void    vecInsert(int num, int size, vector &main, vector &sub);
        void    vecSetChains(int num, int size, vector &main, vector &sub);
        void    vecBinarySearchInsert(vector &mainChain, vector &subChain, size_t index, size_t size);
        void    vecComparePair(int num, int size);
        bool    vecCheckDuplicate();
        
        double  deqTime();
        void    deqMergeInsert(int numOfElement, int sizeOfElement);
        void    deqInsert(int num, int size, deque &main, deque &sub);
        void    deqSetChains(int num, int size, deque &main, deque &sub);
        void    deqBinarySearchInsert(deque &mainChain, deque &subChain, size_t index, size_t size);
        void    deqComparePair(int num, int size);
        bool    deqCheckDuplicate();
};

#endif