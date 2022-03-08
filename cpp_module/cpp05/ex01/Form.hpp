#ifndef __FORM_H__
#define __FORM_H__

#include "Bureaucrat.hpp"

class Form {
private:
	std::string _name;
	boolean _isSigned;
	int _gradeForSign;
	int _gradeForExec;
	static const int GradeTooHighException = 1;
	static const int GradeTooLowException = 150;
public:
	std::string getName() const;
	boolean getIsSigned() const;
	int getGradeForSign() const;
	int getGradeForExec() const;
	void beSinged(Bureaucrat& crat);
	void signForm();
}

std::ostream& operator<<(std::ostream& out, const Form &ref);