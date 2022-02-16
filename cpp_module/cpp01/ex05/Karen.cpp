#include "Karen.hpp"

Karen::Karen() {}

Karen::~Karen() {}

void Karen::debug()
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "This is debug message :(" << std::endl;
}

void Karen::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "This is info message." << std::endl;
}

void Karen::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "! This is warning message !" << std::endl;
}

void Karen::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "!!!! This is ERROR message !!!!" << std::endl;
}

void Karen::complain(std::string level)
{

}