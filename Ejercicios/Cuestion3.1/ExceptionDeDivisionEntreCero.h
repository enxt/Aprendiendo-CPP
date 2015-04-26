#ifndef _EXCEPTIONDEDIVISIONENTRECERO_H_
#define _EXCEPTIONDEDIVISIONENTRECERO_H_

#include <exception>

using namespace std;

class ExceptionDeDivisionEntreCero : public exception {
    public:
        virtual const char* what() const throw() {
            return "Intento de división entre cero.";
        }
};

#endif //_EXCEPTIONDEDIVISIONENTRECERO_H_
