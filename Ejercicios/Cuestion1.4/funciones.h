#include <string>

#ifndef _FUNCIONES_H_
#define _FUNCIONES_H_

void getVariable(std::string *var, const std::string &varPrompt, bool exitOnEmpty, int maxLength, bool isNumber);
bool isNumeric(std::string *var);
bool isNameWord(std::string *var);


#endif // _FUNCIONES_H_