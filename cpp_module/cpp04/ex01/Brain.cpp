#include "Brain.hpp"

std::string Brain::getIdeas(const int i) const {
	if (i >= 0 && i < B_COUNT)
		return ideas[i];
	return NULL;
}

void Brain::setIdeas(std::string str, const int i) {
	if (i >= 0 && i < B_COUNT)
		ideas[i] = str;
}

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &origin) {
	*this = origin;
}

Brain& Brain::operator=(const Brain &origin) {
	if (this != &origin) {
		for (int i = 0; i < B_COUNT; ++i)
			this->ideas[i] = origin.getIdeas(i);
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
