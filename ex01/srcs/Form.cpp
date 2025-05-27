#include <iostream>
#include <ostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void):_isSigned(false),_signGrade(0),_execGrade(0)
{

}


Form::Form(size_t signGrade, size_t execGrade):_isSigned(false),_signGrade(signGrade),_execGrade(execGrade)
{

}

Form::Form(const Form &other):_signGrade(other._signGrade),_execGrade(other._execGrade)
{
  this->_isSigned = other._isSigned;
}

Form::~Form(void)
{

}

Form &Form::operator=(const Form &other)
{
  this->_isSigned = other._isSigned;
  this->_name = other._name;
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
}
