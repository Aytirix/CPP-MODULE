#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include "Contacts.hpp"

#define MAX_CONTACTS 8
#define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER "0123456789"
#define SPECIAL " !\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	void start();
	void add();
	void search();
private:
	Contacts contacts[MAX_CONTACTS];
	std::string input_new_contact(const char *str, Contacts contact, const char *valid);
	bool print_book();
};

#endif