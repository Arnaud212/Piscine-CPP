#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
void	easyfind( T& container, int value)
{
	typename T::iterator iter; // Declare un iterateur 'iter' qui peut parcourir un conteneur T.
	iter = std::find(container.begin(), container.end(), value);
	if (iter != container.end())
	{
		std::cout << value << " exists in the container at position " << (iter - container.begin()) << std::endl;
		return ;
	}
	else
		throw (std::exception());
}

#endif
