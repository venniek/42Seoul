#ifndef __DOG_H__
#define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public virtual Animal {
private:
	Brain* brain;
public:
	void setType(const std::string type);
	void makeSound() const;
	Brain* getBrain() const;
	void setBrain(Brain *brain);

	Dog();
	Dog(std::string type);
	Dog(const Dog &origin);
	Dog& operator=(const Dog &origin);
	~Dog();
};

#endif