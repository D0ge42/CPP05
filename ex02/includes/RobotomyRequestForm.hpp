#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm: public AForm
{
  private:
    std::string _target;
  public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm(void);

    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    void execute(Bureaucrat const &executor) const ;
    std::string getTarget()const;
};

#endif
