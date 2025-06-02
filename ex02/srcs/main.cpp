#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Test: Successfully Shrubberry signed form test🎄\n" << RESET << std::endl;
  {
    try
    {
      Bureaucrat bur("bur",1);
      ShrubberryCreationForm shru("Home");
      bur.signForm(shru);
      bur.executeForm(shru);
      std::cout << std::endl;

    }
    catch (AForm::FormNotSignedException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }

  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Test: Successfully signed Robotomy form test🤖\n" << RESET << std::endl;
  {
    try
    {
      Bureaucrat bur("bur",1);
      RobotomyRequestForm form("myself");
      bur.signForm(form);
      bur.executeForm(form);
      bur.executeForm(form);
      std::cout << std::endl;
    }
    catch (AForm::FormNotSignedException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Test: Successfully signed Presidential form test🗿\n" << RESET << std::endl;
  {
    try
    {
      Bureaucrat bur("bur",1);
      PresidentialPardonForm form("PresidentialForm");
      bur.signForm(form);
      bur.executeForm(form);
      std::cout << std::endl;
    }
    catch (AForm::FormNotSignedException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  /*##############################################################################################*/
  std::cout << BLUE << "\n-- Test: can sign but not execute⛔\n" << RESET << std::endl;
  {
    try
    {
      Bureaucrat bur("bur",10);
      PresidentialPardonForm form("PresidentialForm");
      bur.signForm(form);
      bur.executeForm(form);
      std::cout << std::endl;
    }
    catch (AForm::GradeTooLowException &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  std::cout << BLUE << "\n-- Test: cannot sign or execute⛔\n" << RESET << std::endl;
  {
    try
    {
      Bureaucrat bur("bur",50);
      PresidentialPardonForm form("PresidentialForm");
      bur.signForm(form);
    }
    catch (AForm::GradeTooLowException &e)
    {
      std::cout << e.what() << std::endl;
      try
      {
        Bureaucrat bur("bur",50);
        PresidentialPardonForm form("PresidentialForm");
        bur.executeForm(form);
      }
      catch (AForm::FormNotSignedException &e1)
      {
        std::cout << e1.what() << std::endl;
      }
    }
  }
  std::cout << BLUE << "\n-- Test: Shrubberry copy assignment operator ⚙️\n" << RESET << std::endl;
  {
    ShrubberryCreationForm *form = new ShrubberryCreationForm("ShrubberyOrig");
    ShrubberryCreationForm *form1 = new ShrubberryCreationForm("ShrubberyCopy");
    *form = *form1;
    std:: cout << "ShrubberryForm name: " << form->getName() << std::endl;
    std:: cout << "ShrubberryForm1 name: " << form1->getName() << std::endl;
    std:: cout << "ShrubberryForm target: " << form->getTarget() << std::endl;
    std:: cout << "ShrubberryForm1 target: " << form1->getTarget() << std::endl;
    std::cout << std::endl;
    delete form;
    delete form1;
  }
  std::cout << BLUE << "\n-- Test: Presidential copy assignment operator ⚙️\n" << RESET << std::endl;
  {
    PresidentialPardonForm *form = new PresidentialPardonForm("PresidentialOrig");
    PresidentialPardonForm *form1 = new PresidentialPardonForm("PresidentialCopy");
    *form = *form1;
    std:: cout << "PresidentialForm name: " << form->getName() << std::endl;
    std:: cout << "PresidentialForm name: " << form1->getName() << std::endl;
    std:: cout << "PresidentialForm target: " << form->getTarget() << std::endl;
    std:: cout << "PresidentialForm target: " << form1->getTarget() << std::endl;
    std::cout << std::endl;
    delete form;
    delete form1;
  }
  std::cout << BLUE << "\n-- Test: Robotomy copy assignment operator ⚙️\n" << RESET << std::endl;
  {
    RobotomyRequestForm *form = new RobotomyRequestForm("RobotomyOrig");
    RobotomyRequestForm *form1 = new RobotomyRequestForm("RobotomyCopy");
    *form = *form1;
    std:: cout << "RobotomyForm name: " << form->getName() << std::endl;
    std:: cout << "RobotomyForm name: " << form1->getName() << std::endl;
    std:: cout << "RobotomyForm target: " << form->getTarget() << std::endl;
    std:: cout << "RobotomyForm target: " << form1->getTarget() << std::endl;
    std::cout << std::endl;
    delete form;
    delete form1;
  }
}
