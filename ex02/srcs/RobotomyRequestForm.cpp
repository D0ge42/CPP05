#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <ostream>
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("RobotomyRequestForm",72,45),_target("none")
{
}


RobotomyRequestForm::RobotomyRequestForm(std::string targ):AForm("RobotomyRequestForm",72,45),_target(targ)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm("RobotomyRequestForm",72,45),_target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
  this->_target = other._target;
  return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &bur) const
{
  int coinFlip;
  if (this->getSigned() == false)
    throw FormNotSignedException();
  if (bur.getGrade() > this->getExecGrade())
    throw GradeTooLowException();

  srand(time(NULL));
  std::cout << "\nInitializing ROBOTOMIZATION.." << std::endl;
  std::cout << "Bzbbzbzbzbzbb BZZZZZZZZZ bzzzzzzz zzzz.." << std::endl;
  sleep(1);

  coinFlip = rand() % 2;
  srand(time(NULL));
  if (coinFlip == 1)
    std::cout << WHITE << this->_target + RESET << " has been robotomized successfully 50% of the time ✅" << (char)0xa;
  else
    std::cout << WHITE << this->_target + RESET << " robotomization failed ❌ " << (char)0xa;
}

