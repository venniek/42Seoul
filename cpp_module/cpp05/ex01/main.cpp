#include "Form.hpp"

int main(void) {
	Form form_j("high-level", 5, 1);
	Form form_h("low-level", 140, 130);
	Bureaucrat b_1("b_1", 2);
	Bureaucrat b_2("b_2", 50);

	std::cout << "form_j: " << form_j << std::endl;
	std::cout << "form_h: " << form_h << std::endl;
	std::cout << "b_1: " << b_1 << std::endl;
	std::cout << "b_2: " << b_2 << std::endl;

	form_j.setIsSigned(false);
	b_1.signForm(form_j);
	std::cout << std::endl;
	form_j.setIsSigned(false);
	b_2.signForm(form_j);
	std::cout << std::endl;
	form_h.setIsSigned(false);
	b_1.signForm(form_h);
	std::cout << std::endl;
	form_h.setIsSigned(false);
	b_2.signForm(form_h);
	std::cout << std::endl;

	return 0;
}