#ifndef __AMATERIA_H__
#define __AMATERIA_H__

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria {
protected:
	std::string _type;
public:
	std::string const & getType() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
	
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria &origin);
	virtual ~AMateria();
};

#endif