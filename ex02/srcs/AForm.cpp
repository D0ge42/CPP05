#include <iostream>
#include <ostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void):_name("EL FORMO"),_isSigned(false),_signGrade(0x101010),_execGrade(0x101010)
{
}


AForm::AForm(std::string name, size_t signGrade, size_t execGrade):_name(name),_isSigned(false),_signGrade(signGrade),_execGrade(execGrade)
{
  if (this->_signGrade > 150 || this->_execGrade > 150)
  {
        throw GradeTooLowException();
  }
  if (this->_signGrade < 1 || this->_execGrade < 1)
  {
        throw GradeTooHighException();
  }
}

AForm::AForm(const AForm &other):_name(other.getName()),_signGrade(other._signGrade),_execGrade(other._execGrade)
{
  this->_isSigned = other._isSigned;
}

AForm::~AForm(void)
{

}

AForm &AForm::operator=(const AForm &other)
{
  (void)other;
  return (*this);
}

/* << Operator overload */

std::ostream &operator<<(std::ostream &os, AForm &form)
{
  os << form.getName() << ", form grade: " << form.getSignGrade() << \
    form.getExecGrade() << std::endl;
  return os;
}
/* Bureaucrat grade too high exception */

const char *AForm::GradeTooHighException::what() const throw()
{
  return "GradeTooHighException: grade cannot be higher than 1";
}

const char *AForm::FormNotSignedException::what() const throw()
{
  return "FormNotSignedException: form is not signed!";
}

/* Bureaucrat grade too low exception */

const char *AForm::GradeTooLowException::what() const throw()
{
  return "GradeTooLowException: grade cannot be lower than 150";
}

/* Getters */

std::string AForm::getName() const
{
  return this->_name;
}

size_t AForm::getSignGrade() const
{
  return this->_signGrade;
}

size_t AForm::getExecGrade() const
{
  return this->_execGrade;
}

void AForm::beSigned(Bureaucrat *bur)
{
    if (bur->getGrade() <= this->_signGrade)
    {
      this->_isSigned = true;
    }
    else
      throw GradeTooLowException();
}

bool AForm::getSigned() const
{
  return this->_isSigned;
}
