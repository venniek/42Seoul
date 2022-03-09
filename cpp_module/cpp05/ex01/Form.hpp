#ifndef __FORM_H__
#define __FORM_H__

#include "Bureaucrat.hpp"
#include <iomanip>

class Form {
private:
	std::string _name;
	bool _isSigned;
	int _gradeForSign;
	int _gradeForExec;
public:
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeForSign() const;
	int getGradeForExec() const;
	void beSinged(Bureaucrat& crat);
	void signForm();

	class GradeTooHighException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Form();
	Form(const std::string name);
	Form(const Form& copy);
	Form& operator=(const Form& origin);
	~Form();
};

std::ostream& operator<<(std::ostream& out, const Form &ref);

#endif