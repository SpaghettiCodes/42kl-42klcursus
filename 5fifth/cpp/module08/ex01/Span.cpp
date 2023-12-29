#include "Span.hpp"

Span::Span() : _size(0), _stored(0)
{
}

Span::Span(Span const &ori) :_size(ori._size), _stored(ori._stored)
{
	*this = ori;
}

Span::Span(unsigned int const tab_size) : _size(tab_size),  _stored(0)
{
}

Span::~Span()
{
}

Span &Span::operator=(Span const &ori)
{
	_size = ori._size;
	_stored = ori._stored;

	_tab.clear();

	// back_inserter

	// constructs a back-insert iterator 
	// insert new elements at the end of container'

	// special type of output iterator designed to allow algo that usually overwrite **
	// ** element to insert new element automatically at the end of the container
	std::copy(ori._tab.begin(), ori._tab.end(), back_inserter(_tab));
	return (*this);
}

void	Span::addNumbers(int *tab, unsigned int tab_size)
{
	if ((tab_size + _stored) > _size)
		throw MaxCapacity();

	std::copy(tab, tab + tab_size, back_inserter(_tab));
	_stored += tab_size;
}

void	Span::addNumber(int const to_add)
{
	if (_stored == _size)
		throw Span::MaxCapacity();

	_tab.push_back(to_add);
	++_stored;
}

unsigned int	paranoid_difference(int &x, int &y)
{
	// ensure that x - y only returns positive
	return ( (x > y) ? (x - y) : (y - x));
}

unsigned int	Span::shortestSpan()
{
	if (_stored <= 1)
		throw Span::NotEnoughNum();

	std::vector<int> copy(_tab);
	std::vector<unsigned int> diff;

	// sort from lowest to largest
	// pdf example abit cacat
	std::sort(copy.begin(), copy.end());

	// get the difference between 2 valuesin the array
	std::adjacent_difference(copy.begin(), copy.end(), back_inserter(diff), paranoid_difference);

	// the first result from adjacent_difference will be equal to first element of the array
	diff.erase(diff.begin());

	// take the smallest
	return (*(std::min_element(diff.begin(), diff.end())));
}

unsigned int	Span::longestSpan()
{
	if (_stored <= 1)
		throw Span::NotEnoughNum();

	std::vector<int> copy(_tab);
	std::sort(copy.begin(), copy.end());
	return ((*(copy.rbegin()) - *(copy.begin())));
}

unsigned int	Span::size()
{
	return (_size);
}

unsigned int	Span::stored()
{
	return (_stored);
}
