#include "ClapTrap.hpp"

void ClapTrap::attack(std::string const &target) {
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _ad << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _name << " is attacked! " << amount << " of damages!" << std::endl;
	_ep -= std::min(amount, _ep);
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired... Got " << amount << " of energy points..." << std::endl;
	_ep += amount;
	if (_ep > _initHit) {
		_ep = _initHit;
		std::cout << "Too much energy... Energy point is " << _ep << " now" << std::endl;
	}
}

std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::getHit() const {
	return _hit;
}

unsigned int ClapTrap::getEp() const {
	return _ep;
}

unsigned int ClapTrap::getAd() const {
	return _ad;
}

unsigned int ClapTrap::getInitHit() const {
	return _initHit;
}

void ClapTrap::setName(const std::string &name) {
	_name = name;
}

void ClapTrap::setHit(unsigned int hit) {
	_hit = hit;
}

void ClapTrap::setEp(unsigned int ep) {
	_ep = ep;
}

void ClapTrap::setAd(unsigned int ad) {
	_ad = ad;
}

void ClapTrap::printStatus() {
	std::cout << std::setw(30) << std::setfill('-') <<  _name + "'s status--------------" << std::endl;
	std::cout << "name         : " << _name << std::endl;
	std::cout << "hit point    : " << _hit << std::endl;
	std::cout << "energy point : " << _ep << std::endl;
	std::cout << "attack damage: " << _ad << std::endl;
	std::cout << "initial energy point: " << _initHit << std::endl;
	std::cout << std::setw(30) << "-" << std::endl << std::endl;
	std::setfill('-');
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit(10), _ep(10), _ad(0), _initHit(_hit) {
	std::cout << "ClapTrap " << _name << " start!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origin): _initHit(origin.getInitHit()) {
	*this = origin;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& origin) {
	setName(origin.getName());
	setHit(origin.getHit());
	setEp(origin.getEp());
	setAd(origin.getAd());
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->getName() << " is destroyed" << std::endl;
}