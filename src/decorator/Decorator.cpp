#include <iostream>
#include <vector>

#include "../../include/decorator/Decorator.h"

Decorator::Decorator(IssueComponent *component)
{
    this->component = component;
}

void Decorator::getSnapshot(std::vector<IssueComponent*>& snapshot)
{
    if (component != nullptr) {
        component->getSnapshot(snapshot);
    }
}

void Decorator::print(int level)
{
    component->print(level);
}

void Decorator::printState()
{
    component->printState();
}

void Decorator::execute()
{
    component->execute();
}

int Decorator::getPriority()
{
    return component->getPriority();
}
