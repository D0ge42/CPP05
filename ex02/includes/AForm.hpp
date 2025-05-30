#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class AForm
{
  private:
    const std::string _name;
    bool _isSigned;
    const size_t _signGrade;
    const size_t _execGrade;

  public:
    AForm(void);
    AForm(std::string name, size_t signGrade, size_t execGrade);
    AForm(const AForm &other);
    ~AForm(void);

    AForm &operator=(const AForm &other);

    class GradeTooHighException: public std::exception
    {
      public:
        const char* what() const throw();

    };
    class GradeTooLowException: public std::exception
    {
      public:
        const char* what() const throw();
    };

    std::string getName() const;
    size_t getSignGrade() const;
    size_t getExecGrade() const;
    bool getSigned() const;
    void beSigned(Bureaucrat *bur);
    virtual void execute(Bureaucrat const &executor)const = 0;
};

std::ostream &operator<<(std::ostream &stream, AForm &form);

#endif
