#include <iostream>
#include <vector>

#include "../../include/decorator/Decorator.h"

Decorator::Decorator(IssueComponent *component)
{
    this->component = component;
}

std::vector<IssueComponent *> Decorator::getSnapshot()
{
    return component->getSnapshot();
}

Iterator *Decorator::createIterator()
{
    return component->createIterator();
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