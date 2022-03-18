#include "span.hpp"
#include <ctime>

int main(){
	Span sp = Span(5);
	Span sp1 = Span(10000);
	Span sp2 = Span(3);

	std::cout << std::endl << "=======================================" << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortestspan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestspan: " << sp.longestSpan() << std::endl;
	std::cout << std::endl << "=======================================" << std::endl;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 100; i++){
		sp1.addNumber(rand() % (sp1.getMaxSize() * 10));
	}
	std::cout << "shortestspan: " << sp1.shortestSpan() << std::endl;
	std::cout << "longestspan: " << sp1.longestSpan() << std::endl;
	
	std::cout << std::endl << "=======================================" << std::endl;
	std::cout << "[error test]" << std::endl;
	try {
		sp.addNumber(18);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "shortestspan: " << sp2.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}