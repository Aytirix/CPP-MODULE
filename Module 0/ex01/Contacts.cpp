#include "Contacts.hpp"
#include "main.hpp"

Contacts::Contacts() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

Contacts::~Contacts() {}

// GETTERS

void Contacts::print_contact()
{
	system("clear");
	std::cout << "╔════════════════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║ First name     : " << first_name;
	Space(50 - first_name.length());
	std::cout << "║" << std::endl;
	std::cout << "║ Last name      : " << last_name;
	Space(50 - last_name.length());
	std::cout << "║" << std::endl;
	std::cout << "║ Nickname       : " << nickname;
	Space(50 - nickname.length());
	std::cout << "║" << std::endl;
	std::cout << "║ Phone number   : " << phone_number;
	Space(50 - phone_number.length());
	std::cout << "║" << std::endl;
	std::cout << "║ Darkest secret : " << darkest_secret;
	Space(50 - darkest_secret.length());
	std::cout << "║" << std::endl;
	std::cout << "╚════════════════════════════════════════════════════════════════════╝" << std::endl;
	std::cout << "" << std::endl;
}

std::string Contacts::get_first_name()
{
	return first_name;
}

std::string Contacts::get_last_name()
{
	return last_name;
}

std::string Contacts::get_nickname()
{
	return nickname;
}

std::string Contacts::get_phone_number()
{
	return phone_number;
}

std::string Contacts::get_darkest_secret()
{
	return darkest_secret;
}

// SETTERS

void Contacts::reset()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

void Contacts::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void Contacts::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void Contacts::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void Contacts::set_phone_number(std::string phone_number)
{
	this->phone_number = phone_number;
}

void Contacts::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}
