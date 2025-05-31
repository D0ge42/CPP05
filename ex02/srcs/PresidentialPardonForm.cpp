#include <iostream>
#include <ostream>
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("PresidentialPardonForm",25,5),_target("none")
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string targ):AForm("PresidentialPardonForm",25,5),_target(targ)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm("PresidentialPardonForm",25,5),_target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
  this->_target = other._target;
  return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &bur) const
{
  if (this->getSigned() == false)
    throw FormNotSignedException();
  else if (this->getExecGrade() < bur.getGrade())
    throw GradeTooLowException();
  else
    std::cout << CYAN << this->_target << " has been pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}

