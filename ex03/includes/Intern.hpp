#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <string>

class Intern
{
  public:
    Intern(void);
    Intern(const Intern &other);
    ~Intern(void);

    Intern &operator=(const Intern &other);
    AForm *makeForm(std::string name, std::string target);
};

#endif
