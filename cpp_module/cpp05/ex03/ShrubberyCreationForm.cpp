#include "ShrubberyCreationForm.hpp"


std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	std::ofstream newfile;
	std::string drawing = "               ,@@@@@@@,\n"
							"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
							"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
							"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
							"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
							"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
							"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
							"       |o|        | |         | |\n"
							"       |.|        | |         | |\n"
							"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";

	this->isExecutable(executor);
	newfile.open(_target + "_shrubbery");
	if (newfile.is_open()) {
		newfile << drawing;
		newfile.close();
	}
	std::cout << "Shrubbery Form executed successfully" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery", 145, 137), _target("") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): Form("Shrubbery", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor with target name called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): Form(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &origin) {
		*this = *(dynamic_cast<ShrubberyCreationForm*>(&Form::operator=(origin)));
		this->_target = origin.getTarget();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}