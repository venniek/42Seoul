#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	std::ifstream readFile;
	std::ofstream writeFile;
	std::string::size_type index;
	std::string::size_type prev;
	
	if (ac != 4)
	{
		std::cout << "ERROR: you need 3 argument - filename, s1, s2" << std::endl;
		return 1;
	}
	std::string from(av[2]);
	std::string to(av[3]);
	readFile.open(av[1]);
	if (readFile.is_open())
	{
		writeFile.open(strcat(av[1], ".replace"));
		if (writeFile.is_open())
		{
			while (!readFile.eof())
			{
				std::string str;
				getline(readFile, str);
				prev = 0;
				while (prev < str.size() && (index = str.find(from, prev)) != std::string::npos)
				{
					writeFile << str.substr(prev, index - prev);
					writeFile << to;
					prev = std::min(index + from.size(), str.size());
				}
				writeFile << str.substr(prev);
				if (!readFile.eof())
					writeFile << "\n";
			}
			writeFile.close();
		}
		readFile.close();
	}
	return 0;
}
