#include "Brain.hpp"

std::string Brain::getIdeas(const int i) const {
	return ideas[i];
}

void Brain::setIdeas(std::string str, const int i) {
	ideas[i] = str;
}

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &origin) {
	*this = origin;
}

Brain& Brain::operator=(const Brain &origin) {
	for (int i = 0; i < B_COUNT; ++i)
		this->ideas[i] = origin.getIdeas(i);
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
