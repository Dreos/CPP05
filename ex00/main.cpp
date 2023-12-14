#include "Bureaucrat.hpp"

int main()
{
        Bureaucrat *a = new Bureaucrat();
        Bureaucrat b(2,"jean");
        Bureaucrat c(150,"jeanne");
        try{
                std::cout << b << std::endl;
                b.increment();
                std::cout << b << std::endl;
                b.decrement();
                std::cout << b << std::endl;
                a->increment();
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
                std::cout << e.what() << std::endl;
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
                std::cout << e.what() << std::endl;
        }
        try{
                c.decrement();
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
                std::cout << e.what() << std::endl;
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
                std::cout << e.what() << std::endl;
        }
        delete a;
}