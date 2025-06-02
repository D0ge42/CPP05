#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberryCreationForm.hpp"

AForm *Intern::makeForm(std::string name, std::string target)
{
  std::string available_names[3] =
  {"shrubbery creation",
  "robotomy request",
  "presidential pardon"};
  int i = 0;
  AForm *item = NULL;
  while (i < 3)
  {
    if (name.compare(available_names[i]) == 0)
      break;
    i++;
  }
  switch (i)
  {
    case 0:
      item = new ShrubberryCreationForm(name,target);
      break;
    case 1:
      item = new RobotomyRequestForm(name,target);
      break;
    case 2:
      item = new PresidentialPardonForm(name,target);
      break;
  }
  if (i == 3)
    throw AForm::FormDoesNotExistException();
  return item;
}


Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
  (void)other;
}

Intern::~Intern(void)
{
}

Intern &Intern::operator=(const Intern &other)
{
  (void)other;
  return (*this);
}
