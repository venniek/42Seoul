#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "ICharacter.hpp"

class Character: public ICharacter {
private:
	int _inven_count;
	AMateria* _inventory[INVEN_SIZE];
	std::string _name;
public:
	AMateria* getAMateria(int idx) const;
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
	
	Character();
	explicit Character(const std::string& name);
	Character(const Character& copy);
	Character& operator=(const Character& origin);
	~Character();
};

#endif