#ifndef __INTERN_H__
#define __INTERN_H__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
private:
	std::string forms[3];
	Form* makeforms[3];
	
public:
	const std::string& getForms(const int& idx) const;
	Form* getMakeForms(const int& idx) const;
	Form* makeForm(const std::string& name, const std::string& target) const;

	Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& origin);
	virtual ~Intern();
};

#endif