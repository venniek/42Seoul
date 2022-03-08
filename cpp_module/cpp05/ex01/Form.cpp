#include "Form.hpp"

std::string Form::getName() const {
	return _name;
}

boolean Form::getIsSigned() const {
	return _isSigned;
}

int Form::getGradeForSign() const {
	return _gradeForSign;
}

int Form::getGradeForExec() const {
	return _gradeForExec;
}

void Form::beSinged(Bureaucrat& crat) {
	try {
		if (crat.getGrade() >= GradeTooHighException && crat.getGrade() <= _gradeForSign)
			_isSigned = true;
		else if (crat.getGrade() > GradeTooLowException)
			throw GradeTooLowException;
	}
	catch {

	}
}

void Form::signForm(Bureaucrat& crat) {
	if (_isSigned == true)
		std::cout << crat.getName() << " signs " << this->getName() << std::endl;
	else
		std::cout << crat.getName() << "cannot sign " << this->getName() << " because " << std::endl;
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref) {
	out << std::endl;
	out << std::setw(30) << std::setfill('-') << ref.getName() + "'s status--------" << std::setfill(' ') << std::endl;
	out << std::setw(15) << "name: " << ref.getName() << std::endl;
	out << std::setw(15) << "grade: " << ref.getGrade() << std::endl;
	out << std::setw(30) << std::setfill('-') << "\n" << std::endl;
	out << std::setfill(' ');
	return out;
}