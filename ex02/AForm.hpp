#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
        private :
                const std::string name;
                bool sign;
                const int grade_excecution;
                const int grade_sign;
        public :
                AForm(void);
                virtual ~AForm(void); 
                AForm(AForm const &b);
                AForm &operator=(AForm const &b);
                AForm(std::string name,int grade_excecution ,int grade_sign);

                virtual std::string getName() const = 0 ;
                virtual int getSign() const;
                virtual void beSigned(Bureaucrat const& b);
                class GradeTooHighException : public std::exception
                {
                        public :
                                virtual const char *what() const throw();
                };
                class GradeTooLowException : public std::exception
                {
                        public :
                                virtual const char *what() const throw();
                };
};

std::ostream  & operator<<(std::ostream& os , AForm const& bureau);

#endif