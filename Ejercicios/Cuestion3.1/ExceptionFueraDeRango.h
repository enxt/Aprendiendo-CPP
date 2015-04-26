#ifndef _EXCEPTIONFUERADERANGO_H_
#define _EXCEPTIONFUERADERANGO_H_

#include <exception>

using namespace std;

class ExceptionFueraDeRango : public exception {
    public:
        virtual const char* what() const throw() {
            return "Está fuera de rango.";
        }
};


#endif //_EXCEPTIONFUERADERANGO_H_
