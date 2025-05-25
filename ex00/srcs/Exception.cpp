#include "Exception.hpp"

Exception::Exception(const char *msg):_msg(msg)
{
}

const char* Exception::what() const throw()
{
  return _msg.c_str();
}
