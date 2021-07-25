#include <iostream>
#include <exception>

class UnexpectedException: public std::exception {
    virtual const char* what() const throw()
    {
        return "Unexpected Exception occured";
    }
} UnexpectedEx;