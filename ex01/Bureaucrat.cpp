#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void):name("undefined"),grade(1)
{
        std::cout << "Default bureaucrat constructor called"<< std::endl;
}
Bureaucrat::~Bureaucrat(void)
{
        std::cout << "Destructor Bureaucrat" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat const &b)
        :name(b.name),
        grade(b.grade)
{
        std::cout << "Bureaucrat copy constructor" << std::endl;

}
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
        if(this != &b)
        {
                this->grade = b.grade;
        }
        return (*this);
}
Bureaucrat::Bureaucrat(int grade,std::string name):name(name),grade(grade)
{
        std::cout << "Constructor bureaucrat " << std::endl;
}
int Bureaucrat::getGrade() const 
{
        return(this->grade);
}
const std::string &Bureaucrat::getName() const 
{
        return(this->name);
}
void Bureaucrat::increment()
{
        if(this->grade > 1)
                this->grade = this->grade - 1;
        else
                throw(  Bureaucrat::GradeTooHighException()); 
}
void Bureaucrat::decrement()
{
        if(this->grade < 150)
                this->grade = this->grade + 1;
        else
                throw(  Bureaucrat::GradeTooLowException()); 
}

std::ostream &operator<<(std::ostream& os , Bureaucrat const& bureau )
{
	return(os << bureau.getName() << ", bureaucrat is grade : " << bureau.getGrade()) << std::endl;
}
const char * Bureaucrat::GradeTooLowException::what() const throw()
{
        return("Grade too low");
}
void Bureaucrat::signForm(Form *f) 
{
       try{
                f->beSigned(*this);
       }
       catch(Form::GradeTooLowException &e)
       {
                std::cout << name << " couldn't sign " << f->getName() << " because " << e.what() << std::endl; 
       }
}
const char * Bureaucrat::GradeTooHighException::what() const throw()
{
        return("Grade too high");
}