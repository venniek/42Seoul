// Copyright @bigpel66

#include "Bureaucrat.hpp"

void b_call(const Bureaucrat& b, void (Bureaucrat::*f)(void)) {
	try {
		(*(const_cast<Bureaucrat*>(&b)).*f)();
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what();
	}
}

void b_make(const std::string& name, const int& grade) {
	try {
		Bureaucrat b(name, grade);
		std::cout << b << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what();
	}
}

int main(void) {
	Bureaucrat j("naykim", 1);
	Bureaucrat h("mikyan", 150);

	std::cout << j << std::endl;
	std::cout << h << std::endl << std::endl;

	std::cout << j.getName() << " - increment from " << j.getGrade() << std::endl;
	b_call(j, &Bureaucrat::incrementGrade);
	std::cout << h.getName() << " - decrement from " << h.getGrade() << std::endl;
	b_call(h, &Bureaucrat::decrementGrade);
	std::cout << std::endl;

	std::cout << j.getName() << " - decrement from " << j.getGrade() << std::endl;
	b_call(j, &Bureaucrat::decrementGrade);
	std::cout << h.getName() << " - increment from " << h.getGrade() << std::endl;
	b_call(h, &Bureaucrat::incrementGrade);
	std::cout << std::endl;
	
	std::cout << j.getName() << " - decrement from " << j.getGrade() << std::endl;
	b_call(j, &Bureaucrat::decrementGrade);
	std::cout << h.getName() << " - increment from " << h.getGrade() << std::endl;
	b_call(h, &Bureaucrat::incrementGrade);

	std::cout << "constructor with 0, 151" << std::endl;
	b_make("make_1", 0);
	b_make("make_2", 151);
	return 0;
}