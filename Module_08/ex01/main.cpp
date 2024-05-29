#include "Span.hpp"

int main()
{

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;

	std::cout << std::endl;


	Span test = Span(10);
	test.addNumber(-1000);
	test.addNumber(1000);
	test.addNumber(3000);
	test.addNumber(100);
	test.addNumber(5);
	test.addNumber(50);
	test.addNumber(650);
	test.addNumber(500);
	test.addNumber(350);
	test.addNumber(250);
	try
	{
		test.addNumber(59);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Shortest span : " << test.shortestSpan() << std::endl;
	std::cout << "Longest span : " << test.longestSpan() << std::endl;


	std::cout << std::endl;


	Span big = Span(10000);
	std::srand(std::time(NULL));
	unsigned int rand = std::rand();
	int i = 0;
	while (i < 10000)
	{
		rand = std::rand();
		big.addNumber(rand);
		i++;
	}	
	std::cout << "Shortest span : " << big.shortestSpan() << std::endl;
	std::cout << "Longest span : " << big.longestSpan() << std::endl;


	std::cout << std::endl;


	Span test1 = Span(1000);
	std::vector<int> ok;
	int x = 0;
	while (x < 1000)
	{
		rand = std::rand();
		ok.push_back(rand);
		x++;
	}
	std::vector<int>::iterator it_b = ok.begin();
	std::vector<int>::iterator it_e = ok.end();
	test1.addNumber2(it_b, it_e);
	
	std::cout << "Shortest span : " << test1.shortestSpan() << std::endl;
	std::cout << "Longest span : " << test1.longestSpan() << std::endl;
	return 0;

}
