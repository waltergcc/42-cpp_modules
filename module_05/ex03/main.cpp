#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void debugMessageConstructors(int newline)
{
	std::cout << std::endl;
	std::cout << BLUE << "constructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageStatus(int newline)
{
	std::cout << std::endl;
	std::cout << PURPLE << "status> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageDestructors(int newline)
{
	std::cout << std::endl;
	std::cout << YELLOW << "destructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageAction(std::string action)
{
	std::cout << std::endl;
	std::cout << GREEN << "action> " << RESET;
	if (action.length())
		std::cout << action << std::endl;
}

void exceptionError(std::string message, std::string exception)
{
	std::cerr << RED << "\t" << message << exception << RESET << std::endl;
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl;
}

int	main(void)
{
	{
		titleHeader("SUBJECT TEST");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Intern someRandomIntern;
		AForm* rrf;

		debugMessageAction("Intern try to make a form");
		rrf = someRandomIntern.makeForm("something random", "Bender");

		debugMessageAction("Intern try to make a form");
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << rrf;

		debugMessageDestructors(WITH_NEWLINE);
		delete rrf;

	}
	pressEnter();
	{
		titleHeader("THE ELF TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theDefault = new Bureaucrat();
		Bureaucrat *theFarmer = new Bureaucrat("Sta. Klaus", 100);
		Intern theElf;
		AForm *theForm;

		debugMessageAction("the Elf try to make a form");
		theForm = theElf.makeForm("self-given vacation", "Bahamas");

		debugMessageAction("the Elf try to make a form");
		theForm = theElf.makeForm("shrubbery creation", "North_Pole");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theFarmer);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theFarmer->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			theFarmer->executeForm(*theForm);
			std::cout << "\t" << theFarmer->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theFarmer->getName() + " can't execute ", theForm->getName());
		}

		debugMessageDestructors(WITH_NEWLINE);
		delete theFarmer;
		delete theDefault;
		delete theForm;
	}
	pressEnter();
	{
		titleHeader("THE MUGGLE TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theMadDoctor = new Bureaucrat("Dr. Madness", 1);
		Bureaucrat *theMadAssistent = new Bureaucrat("Mad Assistent", 72);
		Intern theMuggle;
		AForm *theForm;

		debugMessageAction("the Muggle try to make a form");
		theForm = theMuggle.makeForm("call Authorities", "Policy");

		debugMessageAction("the Muggle try to make a form");
		theForm = theMuggle.makeForm("robotomy request", "Bender");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theMadAssistent);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theMadAssistent->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		for (int i = 0; i < 4; i++)
		{
			try
			{
				debugMessageAction("try to execute the form");
				theMadDoctor->executeForm(*theForm);
				std::cout << "\t" << theMadDoctor->getName() << " executed " << theForm->getName() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &e)
			{
				exceptionError("permission denied: ", e.what());
				exceptionError(theMadDoctor->getName() + " can't execute ", theForm->getName());
			}
		}
		debugMessageDestructors(WITH_NEWLINE);
		delete theMadDoctor;
		delete theMadAssistent;
		delete theForm;
	}
	pressEnter();
	{
		titleHeader("THE SECRETARY TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *thePresident = new Bureaucrat("President", 1);
		Bureaucrat *theVicePresident = new Bureaucrat("Vice President", 25);
		Intern theSecretary;
		AForm *theForm;

		debugMessageAction("the Secretary try to make a form");
		theForm = theSecretary.makeForm("leak information", "Press");

		debugMessageAction("the Secretary try to make a form");
		theForm = theSecretary.makeForm("presidential pardon", "Vice President's Son");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theVicePresident);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theVicePresident->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			thePresident->executeForm(*theForm);
			std::cout << "\t" << thePresident->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(thePresident->getName() + " can't execute ", theForm->getName());
		}
		debugMessageDestructors(WITH_NEWLINE);
		delete thePresident;
		delete theVicePresident;
		delete theForm;
	}
	pressEnter();
}
