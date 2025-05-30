#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
  std::cout << "\033[1;91m -- Copy constructor test\033[0m" << (char)0xa;
  Form a("Formoso",42,43);
  {
    Form b = a;
    std::cout << b.getName() << std::endl;
    std::cout << b.getSignGrade() << std::endl;
    std::cout << b.getExecGrade() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\033[1;92m -- Constructor form grade too low\033[0m" << (char)0xa;
  try
  {
    Form b("Form1",151,42);
  }
  catch(Form::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;93m -- Constructor form grade too high\033[0m" << (char)0xa;
  try
  {
    Form b("Form2",0,42);
  }
  catch(Form::GradeTooHighException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;94m -- Constructor exec grade too low\033[0m" << (char)0xa;
  try
  {
    Form b("Form1",30,151);
  }
  catch(Form::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;95m -- Constructor exec grade too high\033[0m" << (char)0xa;
  try
  {
    Form b("Form2",30,0);
  }
  catch(Form::GradeTooHighException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;96m -- Bureaucrat trying to sign higher grade\033[0m" << (char)0xa;
  try
  {
    Bureaucrat bur("Bur",150);
    Form b("Form2",1,1);
    bur.SignForm(b);
  }
  catch(Form::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;97m -- Bureaucrat trying to sign lower grade \033[0m" << (char)0xa;
  try
  {
    Bureaucrat bur("Bur",1);
    Form b("Form2",30,30);
    bur.SignForm(b);
  }
  catch(Form::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  /*##############################################################################*/
  std::cout << "\n\033[1;93m -- Overload << operator \033[0m" << (char)0xa;

  Form test("42",42,42);
  std::cout << test;
}
