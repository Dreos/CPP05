#include "Form.hpp"

Form::Form(void): name("undefined"),grade_excecution(1),grade_sign(1)
{
        std::cout << "Default bureaucrat constructor called"<< std::endl;
}
Form::~Form(void) 
{
        std::cout << "Destructor Form" << std::endl;
}

Form::Form(Form const &b)
        :name(b.name),sign(b.sign),grade_excecution(b.grade_excecution),
        grade_sign(b.grade_sign)
{
        std::cout << "Bureaucrat copy constructor" << std::endl;
}
Form::Form(std::string name,int grade_excecution ,int grade_sign)
        :name(name),grade_excecution(grade_excecution),grade_sign(grade_sign)
{
        sign = 0;
        std::cout << "Constructor bureaucrat " << std::endl;
}
Form &Form::operator=(Form const &b)
{
        if(this != &b)
        {
                this->sign = b.sign;
        }
        return (*this);
}

std::ostream &operator<<(std::ostream& os , Form const& form )
{
	return(os << "Form : " << form.getName() );
}

const char * Form::GradeTooLowException::what() const throw()
{
        return("Grade too low");
}

const char * Form::GradeTooHighException::what() const throw()
{
        return("Grade too high");
}

void Form::beSigned(Bureaucrat const& b)
{
        if(grade_sign >= b.getGrade())
        {
                sign = 1;
                std::cout << b.getName() << " signed " << name;
        }
        else
        {
                throw (Form::GradeTooLowException());
        }
}

int Form::getSign() const 
{
        return(sign);
}

std::string Form::getName() const
{
        return(name);
}