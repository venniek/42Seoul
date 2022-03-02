#ifndef __BRAIN_H__
#define __BRAIN_H__

#include <iostream>
#include <string>

class Brain {
private:
	unsigned int count;
	std::string ideas[100];
public:
	void getIdeas() const;
	void addIdeas(std::string add);
	void removeIdeas();

	Brain();
	Brain(const Brain &origin);
	Brain& operator=(const Brain &origin);
	~Brain();
};

#endif

