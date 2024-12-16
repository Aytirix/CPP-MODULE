#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Aform.hpp"
#include "Colors.hpp"

void test_ShrubberyCreationForm()
{
		std::cout << BOLD YELLOW "Test ShrubberyCreationForm is signed" RESET << std::endl;
	Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 100);
	Aform *tree = new ShrubberyCreationForm("tree");
	try
	{
		std::cout << *bureaucrat << std::endl;
		std::cout << *tree << std::endl;
		bureaucrat->signForm(*tree);
		tree->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete tree;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm execute is not signed" RESET << std::endl;
	Bureaucrat *bureaucrat2 = new Bureaucrat("bureaucrat2", 100);
	Aform *tree2 = new ShrubberyCreationForm("tree2");
	try
	{
		std::cout << *bureaucrat2 << std::endl;
		std::cout << *tree2 << std::endl;
		tree2->execute(*bureaucrat2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat2;
	delete tree2;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm no permission to sign" RESET << std::endl;
	Bureaucrat *bureaucrat3 = new Bureaucrat("bureaucrat3", 150);
	Aform *tree3 = new ShrubberyCreationForm("tree3");
	try
	{
		std::cout << *bureaucrat3 << std::endl;
		std::cout << *tree3 << std::endl;
		bureaucrat3->signForm(*tree3);
		tree3->execute(*bureaucrat3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat3;
	delete tree3;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm no permission to execute" RESET << std::endl;
	Bureaucrat *bureaucrat4 = new Bureaucrat("bureaucrat4", 145);
	Aform *tree4 = new ShrubberyCreationForm("tree4");
	try
	{
		std::cout << *bureaucrat4 << std::endl;
		std::cout << *tree4 << std::endl;
		bureaucrat4->signForm(*tree4);
		tree4->execute(*bureaucrat4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat4;
	delete tree4;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm execute to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat5 = new Bureaucrat("bureaucrat5", 1);
	Aform *tree5 = new ShrubberyCreationForm("tree5");
	try
	{
		std::cout << *bureaucrat5 << std::endl;
		std::cout << *tree5 << std::endl;
		bureaucrat5->signForm(*tree5);
		bureaucrat5->executeForm(*tree5);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat5;
	delete tree5;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test ShrubberyCreationForm execute no permission to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat6 = new Bureaucrat("bureaucrat6", 145);
	Aform *tree6 = new ShrubberyCreationForm("tree6");
	try
	{
		std::cout << *bureaucrat6 << std::endl;
		std::cout << *tree6 << std::endl;
		bureaucrat6->signForm(*tree6);
		bureaucrat6->executeForm(*tree6);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat6;
	delete tree6;
}

void test_RobotomyRequestForm()
{
	std::cout << BOLD YELLOW "Test RobotomyRequestForm is signed" RESET << std::endl;
	Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 1);
	Aform *robot = new RobotomyRequestForm("robot");
	try
	{
		std::cout << *bureaucrat << std::endl;
		std::cout << *robot << std::endl;
		bureaucrat->signForm(*robot);
		robot->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete robot;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test RobotomyRequestForm execute is not signed" RESET << std::endl;
	Bureaucrat *bureaucrat2 = new Bureaucrat("bureaucrat2", 1);
	Aform *robot2 = new RobotomyRequestForm("robot2");
	try
	{
		std::cout << *bureaucrat2 << std::endl;
		std::cout << *robot2 << std::endl;
		robot2->execute(*bureaucrat2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat2;
	delete robot2;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test RobotomyRequestForm no permission to sign" RESET << std::endl;
	Bureaucrat *bureaucrat3 = new Bureaucrat("bureaucrat3", 150);
	Aform *robot3 = new RobotomyRequestForm("robot3");
	try
	{
		std::cout << *bureaucrat3 << std::endl;
		std::cout << *robot3 << std::endl;
		bureaucrat3->signForm(*robot3);
		robot3->execute(*bureaucrat3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat3;
	delete robot3;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test RobotomyRequestForm no permission to execute" RESET << std::endl;
	Bureaucrat *bureaucrat4 = new Bureaucrat("bureaucrat4", 72);
	Aform *robot4 = new RobotomyRequestForm("robot4");
	try
	{
		std::cout << *bureaucrat4 << std::endl;
		std::cout << *robot4 << std::endl;
		bureaucrat4->signForm(*robot4);
		robot4->execute(*bureaucrat4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat4;
	delete robot4;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test RobotomyRequestForm execute to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat5 = new Bureaucrat("bureaucrat5", 1);
	Aform *robot5 = new RobotomyRequestForm("robot5");
	try
	{
		std::cout << *bureaucrat5 << std::endl;
		std::cout << *robot5 << std::endl;
		bureaucrat5->signForm(*robot5);
		bureaucrat5->executeForm(*robot5);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat5;
	delete robot5;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test RobotomyRequestForm execute no permission to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat6 = new Bureaucrat("bureaucrat6", 72);
	Aform *robot6 = new RobotomyRequestForm("robot6");
	try
	{
		std::cout << *bureaucrat6 << std::endl;
		std::cout << *robot6 << std::endl;
		bureaucrat6->signForm(*robot6);
		bureaucrat6->executeForm(*robot6);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat6;
	delete robot6;
}

void test_PresidentialPardonForm()
{
	std::cout << BOLD YELLOW "Test PresidentialPardonForm is signed" RESET << std::endl;
	Bureaucrat *bureaucrat = new Bureaucrat("bureaucrat", 1);
	Aform *presidentForm = new PresidentialPardonForm("presidentForm");
	try
	{
		std::cout << *bureaucrat << std::endl;
		std::cout << *presidentForm << std::endl;
		bureaucrat->signForm(*presidentForm);
		presidentForm->execute(*bureaucrat);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat;
	delete presidentForm;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test PresidentialPardonForm execute is not signed" RESET << std::endl;
	Bureaucrat *bureaucrat2 = new Bureaucrat("bureaucrat2", 1);
	Aform *presidentForm2 = new PresidentialPardonForm("presidentForm2");
	try
	{
		std::cout << *bureaucrat2 << std::endl;
		std::cout << *presidentForm2 << std::endl;
		presidentForm2->execute(*bureaucrat2);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat2;
	delete presidentForm2;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test PresidentialPardonForm no permission to sign" RESET << std::endl;
	Bureaucrat *bureaucrat3 = new Bureaucrat("bureaucrat3", 150);
	Aform *presidentForm3 = new PresidentialPardonForm("presidentForm3");
	try
	{
		std::cout << *bureaucrat3 << std::endl;
		std::cout << *presidentForm3 << std::endl;
		bureaucrat3->signForm(*presidentForm3);
		presidentForm3->execute(*bureaucrat3);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat3;
	delete presidentForm3;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test PresidentialPardonForm no permission to execute" RESET << std::endl;
	Bureaucrat *bureaucrat4 = new Bureaucrat("bureaucrat4", 72);
	Aform *presidentForm4 = new PresidentialPardonForm("presidentForm4");
	try
	{
		std::cout << *bureaucrat4 << std::endl;
		std::cout << *presidentForm4 << std::endl;
		bureaucrat4->signForm(*presidentForm4);
		presidentForm4->execute(*bureaucrat4);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat4;
	delete presidentForm4;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test PresidentialPardonForm execute to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat5 = new Bureaucrat("bureaucrat5", 1);
	Aform *presidentForm5 = new PresidentialPardonForm("presidentForm5");
	try
	{
		std::cout << *bureaucrat5 << std::endl;
		std::cout << *presidentForm5 << std::endl;
		bureaucrat5->signForm(*presidentForm5);
		bureaucrat5->executeForm(*presidentForm5);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat5;
	delete presidentForm5;

	std::cout << std::endl << std::endl << BOLD YELLOW "Test PresidentialPardonForm execute no permission to bureaucrat" RESET << std::endl;
	Bureaucrat *bureaucrat6 = new Bureaucrat("bureaucrat6", 25);
	Aform *presidentForm6 = new PresidentialPardonForm("presidentForm6");
	try
	{
		std::cout << *bureaucrat6 << std::endl;
		std::cout << *presidentForm6 << std::endl;
		bureaucrat6->signForm(*presidentForm6);
		bureaucrat6->executeForm(*presidentForm6);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	delete bureaucrat6;
	delete presidentForm6;
}

int main(void)
{
	system("clear");

	test_ShrubberyCreationForm();

	std::cout << std::endl << std::endl << BOLD YELLOW "Appuyer sur une touche pour continuer le test des : RobotomyRequestForm" RESET << std::endl;
	std::cin.get();
	system("clear");

	test_RobotomyRequestForm();

	std::cout << std::endl << std::endl << BOLD YELLOW "Appuyer sur une touche pour continuer le test des : PresidentialPardonForm" RESET << std::endl;
	std::cin.get();
	system("clear");

	test_PresidentialPardonForm();

	std::cout << std::endl << std::endl << BOLD YELLOW "Appuyer sur une touche pour finir le test" RESET << std::endl;
	std::cin.get();
	system("clear");

	system("rm -f tree_shrubbery");
	system("rm -f tree5_shrubbery");
	return (0);
}
