#ifndef PRIORITY_DECORATOR_H
#define PRIORITY_DECORATOR_H

#include <string>

#include "Decorator.h"

/*
    Adds +1 priority to a component.
*/
class PriorityDecorator : public Decorator
{
public:
    PriorityDecorator(IssueComponent *component);

    int getPriority() override;
};

#endif