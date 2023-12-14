#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <exception>

class Bureaucrat 
{
        private :
                const std::string name;
                int grade;
        public :
                Bureaucrat(void);
                ~Bureaucrat(void); 
                Bureaucrat(Bureaucrat const &b);
                Bureaucrat &operator=(Bureaucrat const &b);
                Bureaucrat(int grade,std::string name);

                int getGrade() const;
                const std::string &getName() const;
                void increment();
                void decrement();
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

std::ostream  & operator<<(std::ostream& os , Bureaucrat const& bureau);

#endif