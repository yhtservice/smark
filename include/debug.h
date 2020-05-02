#pragma once
#include <errno.h>
#include <string.h>
#define PRINT_ERRNO errno << ": " << strerror(errno)
#define DEBUG
#ifdef DEBUG
#  include <iostream>
#  define LOG_VALUE(value) #  value << "=" << value << " "
#  define LOG_NV(name, value) name << "=" << value << " "
#  define DLOG(exp) \
    std::cout << __FILE__ << ":" << __LINE__ << "(" << PRINT_ERRNO << "):" << exp << std::endl;
#else
#  define LOG_VALUE(value)
#  define LOG_NV(name, value)
#  define DLOG(exp)
#endif
#include <sstream>
#define ERR(exp)                              \
  {                                           \
    std::ostringstream oss;                   \
    oss << "(" << PRINT_ERRNO << "):" << exp; \
    DLOG("Error: " << oss.str())              \
    throw oss.str();                          \
  }
