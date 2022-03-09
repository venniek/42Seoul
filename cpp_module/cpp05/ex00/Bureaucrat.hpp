#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <iostream>

#define GRADE_HIGH 1
#define GRADE_LOW 150

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

public:
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException: public std::exception {
	public:
		const char* what(void) const throw();
	};

	Bureaucrat(const std::string name, const int& grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& origin);
	~Bureaucrat();
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref);

#endif