#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stack>
#include <list>
#include <algorithm>
#include <ctime>

class Span
{
	private :
	    unsigned int _n;
	    std::vector<int> tab;
	    Span(void); 

	public : 
        Span(unsigned int n);
        Span(const Span &rhs);
        Span &operator=(const Span &rhs);
        ~Span(void);

        unsigned int        get_n();
        std::vector<int>    getTab();

        void    addNumber(int num);
        void    addNumber2(std::vector<int>::iterator	iter_begin, std::vector<int>::iterator	iter_end);
        int     shortestSpan();
        int     longestSpan();

};

std::ostream& operator<<( std::ostream&, const Span& );

#endif