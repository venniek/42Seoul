#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	std::cout << numbers << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 1000;
		numbers[i] = value;
		mirror[i] = value;
	}
	std::cout << numbers << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "mirror[" << i << "]: " << mirror[i] << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << "=====================copy and assign deep copy test" << std::endl;
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		for (int i = 0; i < MAX_VAL; i++)
			numbers[i] = rand() % 1000;
		std::cout << "================numbers:\n" << numbers << std::endl;
		std::cout << "================tmp:\n" << tmp << std::endl;
		std::cout << "================test:\n" << test << std::endl;
	}

	std::cout << std::endl << "==============exception test" << std::endl;
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try	{
		numbers[std::max(0, MAX_VAL - 1)] = 1000;
		std::cout << numbers << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==================string test" << std::endl;
	Array<std::string> str(MAX_VAL);
	std::string* mirror2 = new std::string[MAX_VAL];
	srand(time(NULL));
	std::cout << str << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 1000;
		str[i] = std::to_string(value);
		mirror2[i] = std::to_string(value);
	}
	std::cout << str << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
		std::cout << "mirror2[" << i << "]: " << mirror2[i] << std::endl;

	delete[] mirror;
	delete[] mirror2;
	return 0;
}
