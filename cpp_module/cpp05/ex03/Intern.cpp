#include "Intern.hpp"

const std::string& Intern::getForms(const int& idx) const {
	return forms[idx];
}

Form* Intern::getMakeForms(const int& idx) const {
	return makeforms[idx];
}

Form* Intern::makeForm(const std::string& name, const std::string& target) const {
	Form* ret = 0;
	std::string forms[3] = {"shrubbery", "robotomy", "president"};
	Form* makeforms[3] = {new ShrubberyCreationForm(target),
							new RobotomyRequestForm(target),
							new PresidentialPardonForm(target) };
	
	for (int i = 0; i < 3; i++) {
		if (name == forms[i])
			ret = makeforms[i];
		else
			delete makeforms[i];
	}
	if (ret == NULL)
		std::cout << "Intern didn't find the form \"" << name << "\"." << std::endl;
	else
		std::cout << "Intern creates the right form \"" << name << "\"." << std::endl;
	return ret;
}

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
	for (int i = 0; i < 3; i++) {
		forms[i] = "";
		makeforms[i] = NULL;
	}
}

Intern::Intern(const Intern& copy) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern& Intern::operator=(const Intern& origin) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &origin) {
		for (int i = 0; i < 3; i++) {
			forms[i] = origin.getForms(i);
			makeforms[i] = origin.getMakeForms(i);
		}
	}
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}
