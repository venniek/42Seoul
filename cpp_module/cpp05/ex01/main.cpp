#include "Form.hpp"

void try_sign(Form& form, Bureaucrat& b) {
	try {
		std::cout << form.getName() << " can be signed by " << b.getName() << " ?" << std::endl;
		form.beSigned(b);
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}
	b.signForm(form);
}

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
	try_sign(form_j, b_1);
	std::cout << std::endl;
	form_j.setIsSigned(false);
	try_sign(form_j, b_2);
	std::cout << std::endl;
	form_h.setIsSigned(false);
	try_sign(form_h, b_1);
	std::cout << std::endl;
	form_h.setIsSigned(false);
	try_sign(form_h, b_2);
	std::cout << std::endl;

	return 0;
}