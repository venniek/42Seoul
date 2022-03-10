#ifndef __FORM_H__
#define __FORM_H__

#include "Bureaucrat.hpp"
#include <iomanip>

class Bureaucrat;

class Form {
private:
	std::string _name;
	bool _isSigned;
	int _gradeForSign;
	int _gradeForExec;
public:
	std::string getName() const;
	bool getIsSigned() const;
	void setIsSigned(bool _bool);
	int getGradeForSign() const;
	int getGradeForExec() const;
	void beSigned(Bureaucrat& crat);
	virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Form();
	Form(const std::string name, const int forSign, const int forExec);
	Form(const Form& copy);
	Form& operator=(const Form& origin);
	virtual ~Form();
};

std::ostream& operator<<(std::ostream& out, const Form &ref);

#endif