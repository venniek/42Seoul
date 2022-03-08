#ifndef __IMATERIASOURCE_H__
#define __IMATERIASOURCE_H__

#include "AMateria.hpp"
#include <string>

#define M_SIZE 4

class IMateriaSource {
public:
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const &type) = 0;
	
	virtual ~IMateriaSource() {}
};

#endif