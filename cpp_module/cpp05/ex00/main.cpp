#include "Bureaucrat.hpp"

int main() {
	Bureaucrat crat150("crat150");
	Bureaucrat crat10("crat10", 10);

	std::cout << crat150;
	std::cout << crat10;

	crat150.DownGrade(5);
	std::cout << crat150;
	crat10.DownGrade(5);
	std::cout << crat10;

	crat150.UpGrade(50);
	std::cout << crat150;
	crat10.UpGrade(50);
	std::cout << crat10;
	
	return 0;
}