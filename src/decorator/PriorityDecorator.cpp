#include "../../include/decorator/PriorityDecorator.h"

PriorityDecorator::PriorityDecorator(IssueComponent *component) : Decorator(component) {}

int PriorityDecorator::getPriority()
{
    return 1 + component->getPriority();
}