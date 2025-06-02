#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberryCreationForm.hpp"
#include <iostream>

int main()
{
  std::cout << BLUE << "Test: intern makes PresidentialPardonForm" << RESET << std::endl;
  {
    try
    {
      Intern test;
      AForm *form = test.makeForm("presidential pardon","me");
      if (form)
        std::cout << *form;
    }
    catch (AForm::FormDoesNotExistException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << BLUE << "Test: intern makes ShrubberryCreationForm" << RESET << std::endl;
  {
    try
    {
      Intern test;
      AForm *form = test.makeForm("shrubbery creation","home");
      if (form)
        std::cout << *form;
    }
    catch (AForm::FormDoesNotExistException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << BLUE << "Test: intern makes RobotomyRequestForm" << RESET << std::endl;
  {
    try
    {
      Intern test;
      AForm *form = test.makeForm("robotomy request","bender");
      if (form)
        std::cout << *form;
    }
    catch(AForm::FormDoesNotExistException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << BLUE << "Test: intern makes non existent form" << RESET << std::endl;
  {
    try
    {
    Intern test;
    AForm *form = test.makeForm("test","42");
    if (form)
      std::cout << *form;
    }
    catch (AForm::FormDoesNotExistException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
}
