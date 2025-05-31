#ifndef SHRUBBERRYCREATIONFORM_HPP
#define SHRUBBERRYCREATIONFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberryCreationForm: public AForm
{
  private:
    std::string _target;
  public:
    ShrubberryCreationForm(void);
    ShrubberryCreationForm(std::string target);
    ShrubberryCreationForm(const ShrubberryCreationForm &other);
    ~ShrubberryCreationForm(void);

    ShrubberryCreationForm &operator=(const ShrubberryCreationForm &other);
    void execute(Bureaucrat const &executor) const ;
};

#endif
