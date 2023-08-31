#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target;

		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		std::string getTarget() const;

		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src);