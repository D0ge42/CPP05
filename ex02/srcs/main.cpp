#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Successfully Shrubberry signed form test\n" << RESET << std::endl;
  {
    Bureaucrat bur("bur",1);
    ShrubberryCreationForm shru("42");
    bur.signForm(shru);
    bur.executeForm(shru);
    std::cout << std::endl;
  }

  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Successfully signed Robotomy form test\n" << RESET << std::endl;
  {
    Bureaucrat bur("bur",1);
    RobotomyRequestForm form("myself");
    bur.signForm(form);
    bur.executeForm(form);
    bur.executeForm(form);
    std::cout << std::endl;
  }
  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Successfully signed Presidential form test\n" << RESET << std::endl;
  {
    Bureaucrat bur("bur",1);
    PresidentialPardonForm form("myself");
    bur.signForm(form);
    bur.executeForm(form);
    std::cout << std::endl;
  }
  /*##############################################################################################*/
}
