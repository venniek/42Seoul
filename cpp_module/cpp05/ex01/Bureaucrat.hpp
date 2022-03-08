#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <string>
#include <iostream>
#include <iomanip>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
	static const int GradeTooHighException = 1;
	static const int GradeTooLowException = 150;

public:
	std::string getName() const;
	int getGrade() const;
	void UpGrade(int up);
	void DownGrade(int down);

	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat &ref);

#endif