#include "Span.hpp"

Span::Span(void)
{}

Span::Span(unsigned int n) : _n(n)
{}

Span::Span(const Span &rhs)
{
    *this = rhs;
}

Span& Span::operator=(const Span &rhs)
{
    if ( this != &rhs)
    {
        _n = rhs._n;
        tab = rhs.tab;
    }
    return(*this);
}

unsigned int Span::get_n()
{
	return (_n);
}

std::vector<int> Span::getTab()
{
	return (tab);
}

void Span::addNumber(int num)
{
	if (tab.size() < _n)
		tab.push_back(num);
	else
		throw std::out_of_range("Span::addNumber: list is full");
}

void Span::addNumber2(std::vector<int>::iterator iter_begin, std::vector<int>::iterator	iter_end)
{
	if (tab.size() < _n)
		tab.insert(tab.end(), iter_begin, iter_end);
	else
		throw std::out_of_range("Span::addNumber: list is full");
}

int Span::shortestSpan()
{
	int curr;
	int next;
	int range;

	std::vector<int> tmp;
	if (tab.size() < 2)
		throw std::out_of_range("Span::shortestSpan: list is empty");
	tmp = tab;
    std::sort(tmp.begin(), tmp.end()); // Trie le tableau de facon croissante
	std::vector<int>::iterator	iter_begin;
	iter_begin = tmp.begin(); // pour avoir le debut
	range = tmp[1] - tmp[0]; // difference entre les 2 premiers
	while (*iter_begin != tmp[tmp.size() - 1])
	{
		curr = *iter_begin;
		iter_begin++;
		next = *iter_begin;
		if (range > (next - curr))  // On verifie d'avoir toujours le plus petit span
			range = next - curr;
	}
	return (range);
}

int Span::longestSpan()
{
	if (tab.size() < 2)
        throw std::out_of_range("Span::shortestSpan: list is empty");
	std::vector<int> tmp;
    tmp = this->tab;
    sort(tmp.begin(), tmp.end()); // Trie le tableau de facon croissante 
	return (tmp[tmp.size() - 1] - tmp[0]); // On fait la diff entre le 1er et le dernier
}

Span::~Span(void)
{}