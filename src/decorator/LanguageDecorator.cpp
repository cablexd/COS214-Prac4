#include <iostream>
#include <vector>

#include "../../include/decorator/LanguageDecorator.h"

LanguageDecorator::LanguageDecorator(std::string languageName, IssueComponent *component) : Decorator(component), languageName(languageName) {}

void LanguageDecorator::print(int level)
{
    component->print(level);
    std::cout << std::string(level * 2, ' ') << "With language: " << languageName << std::endl;
}

std::string LanguageDecorator::getName() {
    return component->getName() + " (" + languageName + ")";
}
