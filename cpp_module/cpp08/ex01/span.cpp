#include "span.hpp"

unsigned int Span::getMaxSize() const {
	return _maxsize;
}

unsigned int Span::getNowSize() const {
	return _store.size();
}

std::vector<int> Span::getStore() const {
	return _store;
}

void Span::addNumber(int number) {
	if (getNowSize() == getMaxSize())
		throw std::out_of_range("Storage is full");
	_store.push_back(number);
}

int Span::shortestSpan() const {
	std::vector<int> tmp = this->_store;
	int ret = -1;

	if (_store.size() <= 1)
		throw std::logic_error("Not enough number(0 or 1)");
	sort(tmp.begin(), tmp.end());
	ret = tmp[1] - tmp[0];
	for (unsigned int i = 1; i < tmp.size() - 1; i++) {
		if (ret > tmp[i + 1] - tmp[i])
			ret = tmp[i + 1] - tmp[i];
	}
	return ret;
}

int Span::longestSpan() const {
	std::vector<int> tmp = this->_store;
	
	if (_store.size() <= 1)
		throw std::logic_error("Not enough number(0 or 1)");
	sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}

const char* Span::NoSpan::what(void) const throw() {
	return "No enough numbers.";
}

Span::Span(): _maxsize(0) {
	std::cout << "--[Span default constructor called]--" << std::endl;
}

Span::Span(unsigned int N): _maxsize(N) {
	std::cout << "--[Span constructor with N called]--" << std::endl;
}

Span::Span(const Span& copy) {
	std::cout << "--[Span copy constructor called]--" << std::endl;
	*this = copy;
}

Span& Span::operator=(const Span& origin) {
	std::cout << "--[Span assignation operator called]--" << std::endl;
	if (this != &origin) {
		this->_maxsize = origin.getMaxSize();
		this->_store.clear();
		std::copy(origin.getStore().begin(), origin.getStore().end(), this->_store.begin());
	}
	return *this;
}

Span::~Span() {
	std::cout << "--[Span destructor called]--" << std::endl;
}
