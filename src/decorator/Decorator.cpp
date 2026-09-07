#include <iostream>
#include <vector>

#include "../../include/decorator/Decorator.h"
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"

Decorator::Decorator(IssueComponent *component) : component(component) {}

void Decorator::getSnapshot(std::vector<IssueComponent *> &snapshot)
{
    if (component != nullptr)
    {
        component->getSnapshot(snapshot);
    }
}

Iterator* Decorator::createIterator(std::string type)
{
    std::vector<IssueComponent *> snapshot;
    snapshot.push_back(this);

    this->getSnapshot(snapshot);

    if (type == "priority")
    {
        std::cout << "Priority Iterator created" << std::endl;
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    std::cout << "DepthFirst Iterator created" << std::endl;
    return new DepthFirstIterator(snapshot);
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
