#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
  std::cout << "\n\033[1;91m -- Constructor grade too low test \033[0m" << std::endl;

  try
  {
    Bureaucrat test("John",151);
  }
  catch(Bureaucrat::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //###################################################################################//

  std::cout << "\n\033[1;91m -- Constructor grade too high test \033[0m" << std::endl;
  try
  {
    Bureaucrat test1("Juhn",0);
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //###################################################################################//

  std::cout << "\n\033[1;94m -- << Operator overload test \033[0m" << std::endl;

  Bureaucrat test3("Jehn",150);
  Bureaucrat test4("Jihn",1);
  std::cout << test3;
  std::cout << test4;

  //###################################################################################//

  std::cout << "\n\033[1;92m -- Decrease Grade past limit \033[0m" << std::endl;

  try
  {
    test3.decreaseGrade();
  }
  catch (Bureaucrat::GradeTooLowException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //###################################################################################//

  std::cout << "\n\033[1;92m -- Increase grade past limit \033[0m" << std::endl;

  try
  {
    test4.increaseGrade();
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << e.what() << std::endl;
  }

  //###################################################################################//

  std::cout << "\n\033[1;94m -- << Copy assignment test \033[0m" << std::endl;

  Bureaucrat test6("John.Jr",30);

  std::cout << "test grade" << test6.getGrade() << std::endl;
  Bureaucrat test5;
  test5 = test6;
  std::cout << "test grade" << test5.getGrade() << std::endl;

  //###################################################################################//

  std::cout << "\n\033[1;94m -- << Copy constructor test \033[0m" << std::endl;

  Bureaucrat test8(Bureaucrat("Jonnie",42));

  std::cout << "test grade" << test8.getGrade() << std::endl;


  std::cout << std::endl;
}
