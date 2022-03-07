#include "Character.hpp"

AMateria* Character::getAMateria(int idx) const {
	return _inventory[idx];
}

std::string& const Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_inven_count > 0 && _inven_count < AMA_SIZE) {
		_inventory[_inven_count] = m;
		++_inven_count;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < inven_count && _inventory[idx]) {
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << "FAIL to unequip" <<std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < AMA_SIZE && _inventory[idx]) {
		_inventory[idx]->use(target);
		return ;
	}
	std::cout << "FAIL to use" << std::endl;
}

Character::Character(): _name(""), _inven_count(0) {
	for (int i = 0; i < INVEN_SIZE; ++i)
		_inventory[i] = NULL;
	std::cout << "Character Default constructor called" << std::endl;
}

explicit Character::Character(const std::string& name): _name(name), _inven_count(0) {
	*this = Character();
	_name = name;
	std::cout << "Character constructor with name \"" << name << std::cout << "\" called" << std::endl;
} 

Character::Character(const Character& copy) {
	*this = copy;
	std::cout << "Character copy constructor called" << std:endl;
}

Character& Character::operator=(const Character& origin) {

}

Character::~Character() {


}