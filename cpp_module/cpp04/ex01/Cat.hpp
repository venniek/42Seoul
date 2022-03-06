#ifndef __CAT_H__
#define __CAT_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
private:
	Brain* brain;
public:
	void setType(const std::string type);
	void makeSound() const;
	Brain* getBrain() const;
	void setBrain();

	Cat();
	Cat(std::string type);
	Cat(const Cat &origin);
	Cat& operator=(const Cat &origin);
	~Cat();
};

#endif