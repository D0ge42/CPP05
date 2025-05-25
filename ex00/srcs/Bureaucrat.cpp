#include "Bureaucrat.hpp"
#include "Exception.hpp"
#include <iostream>
#include <ostream>

void Bureaucrat::decreaseGrade()
{
  try
  {
    this->_grade++;
    if (this->_grade > 150)
      throw Exception("Grade cannot be higher than 150");
  }
  catch (Exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

void Bureaucrat::increaseGrade()
{
  try
  {
    this->_grade--;
    if (this->_grade < 1)
      throw Exception("Grade cannot be lower than 1");
  }
  catch (Exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &bur)
{
  os << bur.getName() << ", bureaucrat grade: " << bur.getGrade() << std::endl;
  return os;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade):_name(name),_grade(grade)
{
  if (this->_grade < 1)
    _grade = 1;
  if (this->_grade > 150)
    _grade = 150;
}

std::string Bureaucrat::getName() const
{
  return this->_name;
}

size_t Bureaucrat::getGrade() const
{
  return this->_grade;
}

Bureaucrat::Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
  this->_grade = other.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
  this->_grade = other._grade;
  return (*this);
}




