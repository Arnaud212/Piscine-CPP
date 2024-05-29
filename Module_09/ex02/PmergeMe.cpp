#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
    *this = rhs;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    vec = rhs.vec;
    deq = rhs.deq;
    return (*this);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printOutput(int ac, char **av, double vecT, double deqT)
{
    std::cout << "Before: " ;
    for (int i = 1; i < ac; i++)
        std::cout << av[i] << " ";
    std::cout << std::endl;
    std::cout << "After: " ;
    for (size_t j = 0; j < deq.size(); j++)
        std::cout << deq[j] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : ";
    std::cout << std::fixed << std::setprecision(6) << vecT << "s" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : ";
    std::cout << std::fixed << std::setprecision(6) << deqT << "s" << std::endl;
}

bool PmergeMe::validInput(char **av)
{
    int i = 1;
    int j = 0;

    while (av[i])
    {
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (false);
            j++;
        }
        j = 0;
        i++;
    }
    return (true);
}

bool PmergeMe::validNumber(char **av)
{
    int  i = 1;
    char *end;
    
    while (av[i])
    {
        errno = 0;
        long long val = std::strtoll(av[i], &end, 10);
        if (end == av[i] || *end != '\0' || errno == ERANGE || val > INT_MAX || val < INT_MIN)
            return false;
        i++;
    }
    return true;
}

void PmergeMe::input(int ac, char **av)
{
    int i = 1;
    int tmp = 0;

    if (!validInput(av))
    {
        std::cerr << "Error: only positive integer." << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!validNumber(av))
    {
        std::cerr << "Error: MaxInt." << std::endl;
        exit(EXIT_FAILURE);
    }
    while(i < ac)
    {
        tmp = atoi(av[i]);
        if (tmp == 0)
        {
            std::cerr << "Error: only positive integer" << std::endl;
            exit(EXIT_FAILURE);
        }
        vec.push_back(tmp);
        deq.push_back(tmp);
        i++;
    }
    if (vecCheckDuplicate() || deqCheckDuplicate())
    {
        std::cerr << "Error: duplicate detected" << std::endl;
        exit(EXIT_FAILURE);
    }
    setJacobsthalNum();
    printOutput(ac, av, vecTime(), deqTime());
}

void PmergeMe::setJacobsthalNum()
{
    jacobsthalNum[0] = 1;
    jacobsthalNum[1] = 3;

    for (int i = 2; i < 30; ++i)
        jacobsthalNum[i] = jacobsthalNum[i - 1] + 2 * jacobsthalNum[i - 2];
}

int PmergeMe::getNextIndex(int index)
{
    if (index == 0)
        return 1;
    if (index == 1)
        return 3;
    if (index - 1 == jacobsthalNum[jacobsthalIndex])
    {
        ++jacobsthalIndex;
        return jacobsthalNum[jacobsthalIndex + 1];
    }
    return (index - 1);
}

//------------------------------- DEQUE -----------------------------------


bool PmergeMe::deqCheckDuplicate()
{
    int size = deq.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (deq[i] == deq[j])
                return true;
        }
    }
    return false;
}

void PmergeMe::deqComparePair(int num, int size) 
{
    dIterator it = deq.begin();

    for (int i = 0; i < num - 1; i += 2)
    {
        dIterator first = it + i * size;
        dIterator second = it + (i + 1) * size;
        if (*first < *second)
            std::swap_ranges(first, second, second);
    }
}


void PmergeMe::deqBinarySearchInsert(deque &mainChain, deque &subChain, size_t index, size_t size)
{
    int left = 0;
    int right = index + numOfInsert;
    dIterator subIt = subChain.begin() + index * size;
    dIterator mainIt = mainChain.begin();

    if (index == 0)
    {
        mainChain.insert(mainIt, subIt, subIt + size);
        return;
    }
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mainChain[mid * size] < *subIt) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    mainChain.insert(mainIt + left * size, subIt, subIt + size);
    ++numOfInsert;
}

void PmergeMe::deqSetChains(int num, int size, deque &main, deque &sub)
{
    dIterator it = deq.begin();

    for (int i = 0; i < num; ++i)
    {
        if (i == num - 1 || i % 2 == 1)
            sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
        else if (i % 2 == 0)
            main.insert(main.end(), it + i * size, it + (i + 1) * size);
    }
}

void PmergeMe::deqInsert(int num, int size, deque &main, deque &sub)
{
    int index = 0;
    jacobsthalIndex = 0;
    numOfInsert = 0;
    int subChainNum = num / 2 + num % 2;

    deqSetChains(num, size, main, sub);
    for (int i = 0; i < subChainNum; ++i)
    {
        index = getNextIndex(index);
        if (index >= subChainNum)
            index = subChainNum;
        deqBinarySearchInsert(main, sub, index - 1, size);
    }
    for (size_t i = 0; i < main.size(); ++i)
        deq[i] = main[i];
}

void PmergeMe::deqMergeInsert(int numOfElement, int sizeOfElement)
{
    if (numOfElement == 1)
        return;
    deque mainChain;
    deque subChain;
    deqComparePair(numOfElement, sizeOfElement);
    deqMergeInsert(numOfElement / 2, sizeOfElement * 2);
    deqInsert(numOfElement, sizeOfElement, mainChain, subChain);
}

double PmergeMe::deqTime()
{
    clock_t start = clock();
    deqMergeInsert(deq.size(), 1);
    clock_t end = clock();
    double dur = double(end - start) / CLOCKS_PER_SEC;
    return (dur);
}

//------------------------------ VECTOR -------------------------------------

bool PmergeMe::vecCheckDuplicate()
{
    int size = vec.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (vec[i] == vec[j])
                return true;
        }
    }
    return false;
}

void PmergeMe::vecComparePair(int num, int size)
{
    vIterator it = vec.begin();

    for (int i = 0; i < num - 1; i += 2)
    {
        vIterator first = it + i * size;
        vIterator second = it + (i + 1) * size;
        if (*first < *second)
            std::swap_ranges(first, second, second);
    }
}

void PmergeMe::vecBinarySearchInsert(vector &mainChain, vector &subChain, size_t index, size_t size)
{
    int left = 0;
    int right = index + numOfInsert;
    vIterator subIt = subChain.begin() + index * size;
    vIterator mainIt = mainChain.begin();

    if (index == 0)
    {
        mainChain.insert(mainIt, subIt, subIt + size);
        return;
    }
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mainChain[mid * size] < *subIt)
            left = mid + 1;
        else
            right = mid - 1;
    }
    mainChain.insert(mainIt + left * size, subIt, subIt + size);
    ++numOfInsert;
}

void PmergeMe::vecSetChains(int num, int size, vector &main, vector &sub) 
{
    vIterator it = vec.begin();

    for (int i = 0; i < num; ++i)
    {
        if (i == num - 1 || i % 2 == 1)
            sub.insert(sub.end(), it + i * size, it + (i + 1) * size);
        else if (i % 2 == 0)
            main.insert(main.end(), it + i * size, it + (i + 1) * size);
    }
}

void PmergeMe::vecInsert(int num, int size, vector &main, vector &sub)
{
    int index = 0;
    jacobsthalIndex = 0;
    numOfInsert = 0;
    int subChainNum = num / 2 + num % 2;

    vecSetChains(num, size, main, sub);
    for (int i = 0; i < subChainNum; ++i)
    {
        index = getNextIndex(index);
        if (index >= subChainNum)
            index = subChainNum;
        vecBinarySearchInsert(main, sub, index - 1, size);
    }
    for (size_t i = 0; i < main.size(); ++i)
        vec[i] = main[i];
}

void PmergeMe::vecMergeInsert(int numOfElement, int sizeOfElement)
{
    if (numOfElement == 1)
        return;
    vector mainChain;
    vector subChain;
    vecComparePair(numOfElement, sizeOfElement);
    vecMergeInsert(numOfElement / 2, sizeOfElement * 2);
    vecInsert(numOfElement, sizeOfElement, mainChain, subChain);
}

double PmergeMe::vecTime()
{
    clock_t start = clock();
    vecMergeInsert(vec.size(), 1);
    clock_t end = clock();
    double dur = double(end - start) / CLOCKS_PER_SEC;
    return (dur);
}
