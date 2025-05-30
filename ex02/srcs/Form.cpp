#include <iostream>
#include <ostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void):_name("EL FORMO"),_isSigned(false),_signGrade(0x101010),_execGrade(0x101010)
{
}


Form::Form(std::string name, size_t signGrade, size_t execGrade):_name(name),_isSigned(false),_signGrade(signGrade),_execGrade(execGrade)
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

Form::Form(const Form &other):_name(other.getName()),_signGrade(other._signGrade),_execGrade(other._execGrade)
{
  this->_isSigned = other._isSigned;
}

Form::~Form(void)
{

}

Form &Form::operator=(const Form &other)
{
  (void)other;
  return (*this);
}

/* << Operator overload */

std::ostream &operator<<(std::ostream &os, Form &form)
{
  os << form.getName() << ", form grade: " << form.getSignGrade() << \
    form.getExecGrade() << std::endl;
  return os;
}
/* Bureaucrat grade too high exception */

const char *Form::GradeTooHighException::what() const throw()
{
  return "GradeTooHighException: grade cannot be higher than 1";
}

/* Bureaucrat grade too low exception */

const char *Form::GradeTooLowException::what() const throw()
{
  return "GradeTooLowException: grade cannot be lower than 150";
}

/* Getters */

std::string Form::getName() const
{
  return this->_name;
}

size_t Form::getSignGrade() const
{
  return this->_signGrade;
}

size_t Form::getExecGrade() const
{
  return this->_execGrade;
}

void Form::beSigned(Bureaucrat *bur)
{
    if (bur->getGrade() <= this->_signGrade)
    {
      this->_isSigned = true;
    }
    else
      throw GradeTooLowException();
}

bool Form::getSigned() const
{
  return this->_isSigned;
}
