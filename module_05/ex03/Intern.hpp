#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &other);
		~Intern();
		
		Intern &operator=(Intern const &other);

		AForm *makeForm(std::string const &form, std::string const &target);
};
