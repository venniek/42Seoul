#include "Bureaucrat.hpp"

const std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade - 1 < GRADE_HIGH)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > GRADE_LOW)
		throw GradeTooLowException();
	++_grade;
}

void Bureaucrat::signForm(Form& form) {
	if (form.getIsSigned() == true)
		std::cout << this->getName() << " signs " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " cannot sign " << form.getName()
		<< " because grade is too low" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
	return "Bureaucrat grade is too high\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
	return "Bureaucrat grade is too low\n";
}

Bureaucrat::Bureaucrat(const std::string name, const int& grade): _name(name), _grade(grade) {
	std::cout << "Bureaucrat constructor with argument called" << std::endl;
	if (_grade < GRADE_HIGH)
		throw GradeTooHighException();
	if (_grade > GRADE_LOW)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
	if (_grade < GRADE_HIGH)
		throw GradeTooHighException();
	if (_grade > GRADE_LOW)
		throw GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& origin) {
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &origin) {
		*(const_cast<std::string*>(&_name)) = origin.getName();
		_grade = origin.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref) {
	out << "<" << ref.getName() << ">, bureaucrat grade is <" << ref.getGrade() << ">" << std::endl;
	return out;
}