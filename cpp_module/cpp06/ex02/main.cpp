#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

Base* generate() {
	int randomNum;
	Base* ret;

	srand((unsigned int)time(NULL));
	randomNum = rand() % 3;
	if (randomNum == 0)
		ret = new A();
	else if (randomNum == 1)
		ret = new B();
	else
		ret = new C();
	return ret;
}

void identify(Base* p) {
	
}


int main() {

}