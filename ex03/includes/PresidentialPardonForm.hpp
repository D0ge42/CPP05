#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm: public AForm
{
  private:
    std::string _target;
  public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(std::string name, std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    void execute(Bureaucrat const &executor) const ;
    std::string getTarget()const;
};

#endif
