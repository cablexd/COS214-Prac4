#include <iostream>

#include "../../include/decorator/LanguageDecorator.h"

LanguageDecorator::LanguageDecorator(std::string languageName, IssueComponent *component) : Decorator(component), languageName(languageName) {}

void LanguageDecorator::print(int level)
{
    component->print(level);
    std::cout << std::string(level * 2, ' ') << "With language: " << languageName << std::endl;
}
