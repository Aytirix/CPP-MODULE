#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void attack();

	private:
		std::string name;
		Weapon& weapon;
};

#endif