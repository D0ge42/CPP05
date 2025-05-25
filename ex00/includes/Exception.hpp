#ifndef Exception_HPP
#define Exception_HPP

#include <string>
class Exception
{
  private:
    const std::string _msg;
  public:
    Exception(const char *msg);
    const char* what() const throw();
};

#endif
