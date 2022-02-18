#ifndef __REPLACE_HPP__
#define __REPLACE_HPP__

#include <fstream>
#include <iostream>
#include <string>

class Replace {
private:
	static void openReadFile(std::string filename, std::string from, std::string to);
	static void openWriteFile(std::string filename, std::string from, std::string to);
	static void replaceFromTo(std::string str, std::string from, std::string to);

public:
	Replace();
	static void startProcess(std::string filename, std::string from, std::string to);
	~Replace();
};

#endif