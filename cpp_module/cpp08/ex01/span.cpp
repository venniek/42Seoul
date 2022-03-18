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
	if (getNowSize() == getMaxSize()) {
		std::cout << "storage is full." << std::endl;
		return;
	}
	_store.push_back(number);
}

void Span::addByIterator( std::vector<int>::iterator begin, std::vector<int>::iterator end) {

}

int Span::shortestSpan() const {

}

int Span::longestSpan() const {

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
