#include "Karen.hpp"

int main() {
	Karen karen;
	
	std::cout << "============debug start===========" << std::endl;
	karen.complain("debug");
	std::cout << std::endl;
	std::cout << "============info start===========" << std::endl;
	karen.complain("info");
	std::cout << std::endl;
	std::cout << "============warning start===========" << std::endl;
	karen.complain("warning");
	std::cout << std::endl;
	std::cout << "============error start===========" << std::endl;
	karen.complain("error");
	std::cout << std::endl;
	std::cout << "============warning start===========" << std::endl;
	karen.complain("warning");
	std::cout << std::endl;

	return 0;
}