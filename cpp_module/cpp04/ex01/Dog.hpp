#ifndef __Dog_H__
#define __Dog_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
private:
	Brain *brain;
public:
	void setType(const std::string type);
	void makeSound() const;
	Brain *getBrain();
	void setBrain(Brain *brain);

	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog& operator=(const Dog &origin);
	~Dog();
};

#endif