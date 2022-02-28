#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

#include <string>
#include <iostream>
#include <iomanip>

class ClapTrap {
private:
	std::string _name;
	unsigned int _hitPoint;
	unsigned int _energyPoint;
	unsigned int _attackDamage;

	const unsigned int _initHit;

public:
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getHit() const;
	unsigned int getEp() const;
	unsigned int getAd() const;
	unsigned int getInitHit() const;

	void setName(const std::string &name);
	void setHit(unsigned int hit);
	void setEp(unsigned int ep);
	void setAd(unsigned int ad);

	void printStatus();

	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& origin);
	ClapTrap& operator=(const ClapTrap& origin);
	~ClapTrap();
};

#endif