#include <iostream>
#include <vector>

#include "../../include/decorator/LanguageDecorator.h"

LanguageDecorator::LanguageDecorator(std::string languageName, IssueComponent *component) : languageName(languageName), Decorator(component) {}

void LanguageDecorator::print()
{
    component->print();
    std::cout << "With language: " << languageName << std::endl;
}