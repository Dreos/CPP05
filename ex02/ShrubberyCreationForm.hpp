#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
	private:
		
};

#endif