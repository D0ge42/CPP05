#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <ostream>
#include <string>
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

    std::string getName() const;
    size_t getGrade() const;
    void increaseGrade() ;
    void decreaseGrade() ;
};

std::ostream &operator<<(std::ostream &stream, Bureaucrat &bur);

#endif
