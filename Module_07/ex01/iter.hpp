#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void    iter( T *tab, size_t size, void (function)(T))
{
    for (size_t i = 0; i < size; i++)
        function(tab[i]);
}

template<typename T>
void    print(T element)
{
    std::cout << element << std::endl;
}

#endif