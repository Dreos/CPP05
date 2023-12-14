#include "AForm.hpp"

AForm::AForm(void): name("undefined"),grade_excecution(1),grade_sign(1)
{
        std::cout << "Default AFORM constructor called"<< std::endl;
}
AForm::~AForm(void) 
{
        std::cout << "Destructor AFORM" << std::endl;
}

AForm::AForm(AForm const &b)
        :name(b.name),sign(b.sign),grade_excecution(b.grade_excecution),
        grade_sign(b.grade_sign)
{
        std::cout << "AFORM copy constructor" << std::endl;
}
AForm::AForm(std::string name,int grade_excecution ,int grade_sign)
        :name(name),grade_excecution(grade_excecution),grade_sign(grade_sign)
{
        sign = 0;
        std::cout << "Constructor AFORM" << std::endl;
}
AForm &AForm::operator=(AForm const &b)
{
        if(this != &b)
        {
                this->sign = b.sign;
        }
        return (*this);
}

std::ostream &operator<<(std::ostream& os , AForm const& form )
{
	return(os << "Form : " << form.getName() );
}

const char * AForm::GradeTooLowException::what() const throw()
{
        return("Grade too low");
}

const char * AForm::GradeTooHighException::what() const throw()
{
        return("Grade too high");
}

void AForm::beSigned(Bureaucrat const& b)
{
        if(grade_sign >= b.getGrade())
        {
                sign = 1;
                std::cout << b.getName() << " signed " << name;
        }
        else
        {
                throw (AForm::GradeTooLowException());
        }
}

int AForm::getSign() const 
{
        return(sign);
}

std::string AForm::getName() const
{
        return(name);
}