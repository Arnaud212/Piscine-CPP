#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack(void);
        MutantStack(const MutantStack<T> &rhs);
        MutantStack &operator=(const MutantStack<T> &rhs);
        ~MutantStack(void);

        typedef typename std::stack<T>::container_type::iterator iterator;
    	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator        begin();
        const_iterator   begin() const;

        iterator        end();
        const_iterator  end() const;

};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &rhs)
{
    *this = rhs;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
    this->c = rhs.c;
    return (*this);
}

template <typename T>
typename MutantStack<T>::iterator  MutantStack<T>::begin()
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator  MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
MutantStack<T>::~MutantStack()
{}

#endif
