#include "PhoneBook.hpp"
#include "Contacts.hpp"
#include "main.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contacts() {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::input_new_contact(const char *str, Contacts &contact, const char *valid)
{
	contact.print_contact();
	std::string input;
	bool valid_input = true;
	while (std::cin)
	{
		std::cout << "Please enter the " << str << " of the contact > ";
		std::getline(std::cin, input);
		valid_input = true;
		if (input.empty())
		{
			contact.print_contact();
			std::cout << "Input cannot be empty. Please try again." << std::endl;
			continue;
		}
		if (input.length() > 50)
		{
			contact.print_contact();
			std::cout << "Input cannot be longer than 50 characters. Please try again." << std::endl;
			continue;
		}
		for (size_t i = 0; i < input.length(); i++)
		{
			if (strchr(valid, input[i]) == NULL)
			{
				contact.print_contact();
				std::cout << "Invalid input. Please try again." << std::endl;
				valid_input = false;
				break;
			}
		}
		if (valid_input)
			break;
	}
	return input;
}

void PhoneBook::add()
{
	static int i = 0;
	if (i == MAX_CONTACTS)
		i = 0;
	contacts[i].reset();
	contacts[i].set_first_name(input_new_contact("First name", contacts[i], ALPHA NUMBER SPECIAL));
	contacts[i].set_last_name(input_new_contact("Last name", contacts[i], ALPHA NUMBER SPECIAL));
	contacts[i].set_nickname(input_new_contact("Nickname", contacts[i], ALPHA NUMBER SPECIAL));
	contacts[i].set_phone_number(input_new_contact("Phone number", contacts[i], NUMBER));
	contacts[i].set_darkest_secret(input_new_contact("Darkest secret", contacts[i], ALPHA NUMBER SPECIAL));
	contacts[i].print_contact();
	i++;
}
bool PhoneBook::print_book()
{
	system("clear");
	if (contacts[0].get_first_name().empty())
	{

		std::cout << "╔══════════════════════════════════════════════════╗" << std::endl;
		std::cout << "║                PhoneBook is empty                ║" << std::endl;
		std::cout << "╚══════════════════════════════════════════════════╝" << std::endl;
		return false;
	}
	std::cout << "╔═══════════╦════════════╦════════════╦════════════╗" << std::endl;
	std::cout << "║   Index   ║ First name ║ Last name  ║  Nickname  ║" << std::endl;
	std::cout << "╠═══════════╬════════════╬════════════╬════════════╣" << std::endl;

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (contacts[i].get_first_name().empty())
			continue;
		std::cout << "║";
		std::cout << " " << std::setw(9) << i + 1 << " ║";
		if (contacts[i].get_first_name().length() > 10)
			std::cout << " " << std::setw(9) << contacts[i].get_first_name().substr(0, 9) << ". ║";
		else
			std::cout << " " << std::setw(10) << contacts[i].get_first_name() << " ║";
		if (contacts[i].get_last_name().length() > 10)
			std::cout << " " << std::setw(9) << contacts[i].get_last_name().substr(0, 9) << ". ║";
		else
			std::cout << " " << std::setw(10) << contacts[i].get_last_name() << " ║";
		if (contacts[i].get_nickname().length() > 10)
			std::cout << " " << std::setw(9) << contacts[i].get_nickname().substr(0, 9) << ". ║" << std::endl;
		else
			std::cout << " " << std::setw(10) << contacts[i].get_nickname() << " ║" << std::endl;
	}
	std::cout << "╚═══════════╩════════════╩════════════╩════════════╝" << std::endl;
	return true;
}

void PhoneBook::search()

{
	if (PhoneBook::print_book() == false)
		return;
	std::string index;
	while (std::cin)
	{
		std::cout << "Please enter the index of the contact you would like to view > ";
		std::getline(std::cin, index);
		if (index.empty())
		{
			PhoneBook::print_book();
			std::cout << "Input cannot be empty. Please try again." << std::endl;
			continue;
		}
		if (index.length() > 1)
		{
			PhoneBook::print_book();
			std::cout << "Input cannot be longer than 1 character. Please try again." << std::endl;
			continue;
		}
		if (index[0] < '1' || index[0] > '8')
		{
			PhoneBook::print_book();
			std::cout << "Invalid input. Please try again." << std::endl;
			continue;
		}
		if (contacts[index[0] - '1'].get_first_name().empty())
		{
			PhoneBook::print_book();
			std::cout << "Contact does not exist. Please try again." << std::endl;
			continue;
		}
		break;
	}
	contacts[index[0] - '1'].print_contact();
}

void PhoneBook::start()
{
	std::string command;
	while (std::cin)
	{
		system("clear");
		std::cout << "Welcome to PhoneBook!" << std::endl;
		std::cout << "The available commands are ADD, SEARCH, and EXIT." << std::endl;
		no_reset:
		std::cout << "\nCommand > ";
		std::getline(std::cin, command);
		if (command == "ADD")
		{
			PhoneBook::add();
			std::cout << "Contact added." << std::endl;
			goto no_reset;
		}
		else if (command == "SEARCH")
		{
			PhoneBook::search();
			goto no_reset;
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook..." << std::endl;
			return;
		}
	}
}