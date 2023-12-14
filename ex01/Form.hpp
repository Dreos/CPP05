#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form 
{
        private :
                const std::string name;
                bool sign;
                const int grade_excecution;
                const int grade_sign;
        public :
                Form(void);
                ~Form(void); 
                Form(Form const &b);
                Form &operator=(Form const &b);
                Form(std::string name,int grade_excecution ,int grade_sign);

                std::string getName() const ;
                int getSign() const;
                void beSigned(Bureaucrat const& b);
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

std::ostream  & operator<<(std::ostream& os , Form const& bureau);

#endif