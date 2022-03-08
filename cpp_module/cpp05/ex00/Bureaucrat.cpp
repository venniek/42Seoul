#include "Bureaucrat.hpp"

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::UpGrade(int up) {
	std::cout << "let's upgrade " << _name << "'s grade about " << up << std::endl;
	try {
		if (_grade - up < Bureaucrat::GradeTooHighException) {
			throw EXCEPTION;
		}
		_grade -= up;
		std::cout << "Upgrade succeed. Now grade is " << _grade << "." << std::endl;
	}
	catch(int expn) {
		std::cout << "Too high grade. Upgrade failed." << std::endl;
	}
}

void Bureaucrat::DownGrade(int down) {
	std::cout << "let's downgrade " << _name << "'s grade about " << down << std::endl;
	try {
		if (_grade + down > Bureaucrat::GradeTooLowException) {
			throw EXCEPTION;
		}
		_grade += down;
		std::cout << "Downgrade succeed. Now grade is " << _grade << "." << std::endl;
	}
	catch(int expn) {
		std::cout << "Too low grade. Downgrade failed." << std::endl;
	}
}

Bureaucrat::Bureaucrat(std::string name): _name(name), _grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) { }

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref) {
	out << std::endl;
	out << std::setw(30) << std::setfill('-') << ref.getName() + "'s status--------" << std::setfill(' ') << std::endl;
	out << std::setw(15) << "name: " << ref.getName() << std::endl;
	out << std::setw(15) << "grade: " << ref.getGrade() << std::endl;
	out << std::setw(30) << std::setfill('-') << "\n" << std::endl;
	out << std::setfill(' ');
	return out;
}