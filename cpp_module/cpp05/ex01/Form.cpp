#include "Form.hpp"

std::string Form::getName() const {
	return _name;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeForSign() const {
	return _gradeForSign;
}

int Form::getGradeForExec() const {
	return _gradeForExec;
}

void Form::beSinged(Bureaucrat& crat) {
	
}

void Form::signForm(Bureaucrat& crat) {
	if (_isSigned == true)
		std::cout << crat.getName() << " signs " << this->getName() << std::endl;
	else
		std::cout << crat.getName() << "cannot sign " << this->getName() << " because " << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Form &ref) {
	out << std::endl;
	out << std::setw(30) << std::setfill('-') << ref.getName() + "'s status--------" << std::setfill(' ') << std::endl;
	out << std::setw(20) << "name: " << ref.getName() << std::endl;
	out << std::setw(20) << "isSigned: " << (ref.getIsSigned() == true ? "true" : "false") << std::endl;
	out << std::setw(20) << "grade for sign: " << ref.getGradeForSign() << std::endl;
	out << std::setw(20) << "grade for execute: " << ref.getGradeForExec() << std::endl;
	out << std::setw(30) << std::setfill('-') << "\n" << std::endl;
	out << std::setfill(' ');
	return out;
}

	// std::string _name;
	// bool _isSigned;
	// int _gradeForSign;
	// int _gradeForExec;