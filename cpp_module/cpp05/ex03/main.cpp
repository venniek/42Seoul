#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <ctime>

int	main(void)
{
	Intern intern;
	Bureaucrat naykim("naykim", 5);
	Form *form;

	std::cout << "\n===========this one doesn't exist" << std::endl;
	form = intern.makeForm("this one doesn't exist", "Justin");
	if (form)
		delete form;

	std::cout << "\n===========president" << std::endl;
	form = intern.makeForm("president", "Maynard");
	form->beSigned(naykim);
	form->execute(naykim);
	if (form)
		delete form;

	std::cout << "\n===========shrubbery" << std::endl;
	form = intern.makeForm("shrubbery", "Danny");
	form->beSigned(naykim);
	form->execute(naykim);
	if (form)
		delete form;

	std::cout << "\n===========robotomy" << std::endl;
	srand((unsigned int)time(NULL));
	form = intern.makeForm("robotomy", "Adam");
	form->beSigned(naykim);
	form->execute(naykim);
	if (form)
		delete form;

	return 0;
}