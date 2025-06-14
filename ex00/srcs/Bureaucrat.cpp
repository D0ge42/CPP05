#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

/* Function to decrease grade.
 * Exception is thrown if grade goes past limit.
 * Catch has to take either a reference or a pointer.*/

void Bureaucrat::decreaseGrade()
{
    this->_grade++;
    if (this->_grade > 150)
      throw Bureaucrat::GradeTooLowException();
}

/* Function to increase grade.
 * Exception is thrown if grade goes past limit.
 * Catch has to take either a reference or a pointer.*/

void Bureaucrat::increaseGrade()
{
    this->_grade--;
    if (this->_grade < 1)
      throw Bureaucrat::GradeTooHighException();
}

/* << Operator overload */

std::ostream &operator<<(std::ostream &os, Bureaucrat &bur)
{
  os << bur.getName() << ", bureaucrat grade: " << bur.getGrade() << std::endl;
  return os;
}

/* Bureaucrat constructor with parameters name and grade.
 * Exception is thrown if grade is too high or too low.
 * Catched in the main function.*/

Bureaucrat::Bureaucrat(std::string name, size_t grade):_name(name),_grade(grade)
{
  if (this->_grade < 1)
  {
    throw Bureaucrat::GradeTooHighException();
    _grade = 1;
  }
  if (this->_grade > 150)
  {
    throw Bureaucrat::GradeTooLowException();
    _grade = 150;
  }
}

/* Bureaucrat grade too high exception */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "GradeTooHighException: grade cannot be higher than 1";
}

/* Bureaucrat grade too low exception */

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "GradeTooLowException: grade cannot be lower than 150";
}

/* Getters */

std::string Bureaucrat::getName() const
{
  return this->_name;
}

size_t Bureaucrat::getGrade() const
{
  return this->_grade;
}

/* Constructors and Destructors */

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
  this->_grade = other.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  this->_grade = other._grade;
  return (*this);
}

Bureaucrat::~Bureaucrat(void)
{

}


