#include "Converter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error : program accepts only one argument. Not less, not more." << std::endl;
		return (1);
	}
	try
	{
		Converter xyz(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}