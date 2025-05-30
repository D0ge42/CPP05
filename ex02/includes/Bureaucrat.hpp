#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <exception>
#include <ostream>
#include <string>

class Form;

class Bureaucrat
{
  private:
    const std::string _name;
    size_t _grade;
  public:
    Bureaucrat(void);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat(void);
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat(std::string name, size_t grade);
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
    size_t getGrade() const;
    void increaseGrade() ;
    void decreaseGrade() ;
    void SignForm(Form &form);
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bur);

#endif
