#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>
#include <ostream>
#include <iostream>
#include <cstdlib>
#include <cstring>

class Contacts
{
public:
	Contacts();
	~Contacts();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_nickname(std::string nickname);
	void set_phone_number(std::string phone_number);
	void set_darkest_secret(std::string darkest_secret);
	void reset();
	void print_contact();

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif