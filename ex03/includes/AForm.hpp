#ifndef FORM_HPP
#define FORM_HPP

#define BLACK "\e[1;90m"
#define RED "\e[1;91m"
#define GREEN "\e[1;92m"
#define YELLOW "\e[1;93m"
#define BLUE "\e[1;94m"
#define MAGENTA "\e[1;95m"
#define CYAN "\e[1;96m"
#define WHITE "\e[1;97m"
#define RESET "\e[0m"

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>
#include <string>

class AForm
{
  private:
    const std::string _name;
    std::string _target;
    bool _isSigned;
    const size_t _signGrade;
    const size_t _execGrade;

  public:
    AForm(void);
    AForm(std::string name,  size_t signGrade, size_t execGrade);
    AForm(const AForm &other);
    virtual ~AForm(void);

    AForm &operator=(const AForm &other);

    class FormDoesNotExistException: public std::exception
    {
      public:
        const char* what() const throw();

    };
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
    class FormNotSignedException: public std::exception
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
    virtual std::string getTarget() const;
};

std::ostream &operator<<(std::ostream &stream, AForm &form);

#endif
