#include "Character.hpp"

AMateria* Character::getAMateria(int idx) const {
	return _inventory[idx];
}

std::string const &Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (_invenCount > 0 && _invenCount < INVEN_SIZE) {
		_inventory[_invenCount] = m;
		++_invenCount;
	}
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < _invenCount && _inventory[idx]) {
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << "FAIL to unequip" <<std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < INVEN_SIZE && _inventory[idx]) {
		_inventory[idx]->use(target);
		return ;
	}
	std::cout << "FAIL to use" << std::endl;
}

Character::Character(): _name(""), _invenCount(0) {
	for (int i = 0; i < INVEN_SIZE; ++i)
		_inventory[i] = NULL;
	std::cout << "Character Default constructor called" << std::endl;
}

Character::Character(const std::string& name) {
	*this = Character();
	_name = name;
	std::cout << "Character constructor with name \"" << name << std::cout << "\" called" << std::endl;
} 

Character::Character(const Character& copy) {
	*this = copy;
	std::cout << "Character copy constructor called" << std::endl;
}

Character& Character::operator=(const Character& origin) {
	this->_invenCount = 0;
	for (int i = 0; i < INVEN_SIZE; i++) {
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = origin._inventory[i];
		if (origin._inventory[i])
			this->_invenCount++;
	}
	std::cout << "Character assignation operator called" << std::endl;
	return *this;
}

Character::~Character() {
	std::cout << "Character " << _name << " destructor called" << std::endl;
}