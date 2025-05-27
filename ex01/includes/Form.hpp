#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class Form
{
  private:
    std::string _name;
    bool _isSigned;
    const size_t _signGrade;
    const size_t _execGrade;

  public:
    Form(void);
    Form(size_t signGrade, size_t execGrade);
    Form(const Form &other);
    ~Form(void);

    Form &operator=(const Form &other);

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
    void beSigned(Bureaucrat *bur);
};

std::ostream &operator<<(std::ostream &stream, Form &form);

#endif
