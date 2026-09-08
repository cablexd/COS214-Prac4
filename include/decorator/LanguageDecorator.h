#ifndef LANGUAGE_DECORATOR_H
#define LANGUAGE_DECORATOR_H

#include <string>

#include "Decorator.h"

/*
    Prints the language specified in this decorator when the component is printed.
*/
class LanguageDecorator : public Decorator
{
private:
    std::string languageName;

public:
    LanguageDecorator(std::string languageName, IssueComponent *component);

    void print(int level) override;
};

#endif
