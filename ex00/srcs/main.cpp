#include "Bureaucrat.hpp"
#include "Exception.hpp"
#include <iostream>

int main()
{
  std::cout << "\n\033[1;91m -- Overload << test \033[0m" << std::endl;
  Bureaucrat test("John",149);
  Bureaucrat test1("Juhn",1);
  Bureaucrat test2("Jihn", 0);
  Bureaucrat test3("Jahn",33);
  std::cout << test;
  std::cout << test1;
  std::cout << test2;
  std::cout << test3;


  std::cout << "\n\033[1;92m -- Grade too high \033[0m" << std::endl;

  test1.increaseGrade();


  std::cout << "\n\033[1;92m -- Grade too low \033[0m" << std::endl;

  test.decreaseGrade();
  test.decreaseGrade();
  std::cout << std::endl;
}
