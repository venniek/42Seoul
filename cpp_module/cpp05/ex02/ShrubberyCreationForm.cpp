#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	std::ofstream writeFile;
	std::string to;
	std::string::size_type prev;
	std::string::size_type index;
	int ret = 0;

	to = av[3];
	writeFile.open(filename + ".replace");
	if (writeFile.is_open()) {
		while (!readFile.eof())
		{
			std::string str;
			getline(readFile, str);
			if (!readFile.eof())
				str += "\n";
			prev = 0;
			while (prev < str.size() && (index = str.find(from, prev)) != std::string::npos) {
				writeFile << str.substr(prev, index - prev);
				writeFile << to;
				prev = std::min(index + from.size(), str.size());
			}
			writeFile << str.substr(prev);
		}
		writeFile.close();
	}
	else {
		std::cout << "FAIL to open writeFile: " << filename + ".replace" << std::endl;
		ret = 1;
	}

}


ShrubberyCreationForm::ShrubberyCreationForm(): Form("") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
	_gradeForSign = 145;
	_gradeForExec = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name): Form("") {
	std::cout << "ShrubberyCreationForm constructor with argument called" << std::endl;
	_gradeForSign = 145;
	_gradeForExec = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): Form(copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origin) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {


}