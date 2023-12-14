#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
	private:
		
};

#endif