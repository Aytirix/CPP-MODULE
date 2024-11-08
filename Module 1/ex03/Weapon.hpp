#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
	Weapon(const std::string& weapon);
	~Weapon();
	const std::string getType();
	void setType(const std::string& weapon);

	private:
		std::string weapon;
};

#endif