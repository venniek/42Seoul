#include "PresidentialPardonForm.hpp"

const std::string& PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	this->isExecutable(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(): Form("President", 25, 5), _target("") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): Form("President", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor with target called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): Form(copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origin) {
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &origin) {
		*this = *(dynamic_cast<PresidentialPardonForm*>(&Form::operator=(origin)));
		this->_target = origin.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
