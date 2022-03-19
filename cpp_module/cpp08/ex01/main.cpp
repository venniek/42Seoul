#include "span.hpp"
#include <ctime>

#define COUNT 10000

int main(){
	Span sp = Span(5);
	Span sp1 = Span(COUNT);
	Span sp2 = Span(3);

	std::cout << std::endl << "=======================================" << std::endl;
	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		for (unsigned long i = 0; i < sp.getStore().size(); i++) {
			std::cout << sp.getStore()[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "shortestspan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestspan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;
	try {
		std::vector<int> newv;
		srand((unsigned int)time(NULL));
		for (int i = 0; i < COUNT; i++)
			newv.push_back(rand() % (COUNT * 100));
		sp1.addByIterator(newv.begin(), newv.end());
		std::cout << "shortestspan: " << sp1.shortestSpan() << std::endl;
		std::cout << "longestspan: " << sp1.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[error test]" << std::endl;
	try {
		std::cout << "test addNumber() when sp is full" << std::endl;
		sp.addNumber(18);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "test shortestSpan() when sp2 is empty" << std::endl;
		std::cout << "shortestspan: " << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}