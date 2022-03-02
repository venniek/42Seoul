#include "Brain.hpp"

void Brain::getIdeas() const {
	std::cout << "=========================" << std::endl;
	std::cout << "Here are ideas" << std::endl;
	for (unsigned int i = 0; i < count; ++i)
		std::cout << i << ": " << ideas[i] << std::endl;
	std::cout << "=========================" << std::endl;
}

void Brain::addIdeas(std::string add) {
	if (count >= 100)
		std::cout << "there is no space for new string" << std::endl;
	else
	{
		ideas[count] = add;
		++count;
	}
}

void Brain::removeIdeas() {
	if (count <= 0)
		std::cout << "there is no idea to remove" << std::endl;
	else
	{
		--count;
		ideas[count] = "";
	}
}

Brain::Brain(): count(0) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &origin) {
	*this = origin;
}

Brain& Brain::operator=(const Brain &origin) {
	for (int i = 0; origin.ideas[i]; ++i)
		this->ideas[i] = origin.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
