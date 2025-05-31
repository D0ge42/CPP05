#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <ostream>

/* Function to decrease grade.
 * Exception is thrown if grade goes past limit.
 * Catch has to take either a reference or a pointer.*/

void Bureaucrat::decreaseGrade()
{
  try
  {
    this->_grade++;
    if (this->_grade > 150)
      throw Bureaucrat::GradeTooLowException();
  }
  catch (Bureaucrat::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }
}

/* Function to increase grade.
 * Exception is thrown if grade goes past limit.
 * Catch has to take either a reference or a pointer.*/

void Bureaucrat::increaseGrade()
{
  try
  {
    this->_grade--;
    if (this->_grade < 1)
      throw Bureaucrat::GradeTooHighException();
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << e.what() << std::endl;
  }
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

void Bureaucrat::signForm(AForm &form)
{
  form.beSigned(this);
  if (form.getSigned() == true)
      std::cout << YELLOW << this->_name << " signed " << RESET << form.getName() << std::endl;
  else
      std::cout << RED << this->_name << " couldn't sign " << RESET << form.getName()
        << "because " << "grade too  low" << std::endl;
}

void Bureaucrat::executeForm(AForm const& form)
{
  if (this->_grade < form.getExecGrade())
  {
    form.execute(*this);
    std::cout << GREEN << this->getName() << RESET << " executed " << form.getName() << std::endl;
  }
  else
  {
    std::cout << RED << this->getName() << RESET << " couldn't sign form because its grade is too low" << std::endl;
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

Bureaucrat::Bureaucrat(void):_name(""),_grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):_name(other.getName())
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


