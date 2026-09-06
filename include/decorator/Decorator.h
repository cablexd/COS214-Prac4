#ifndef DECORATOR_H
#define DECORATOR_H

#include "../composite/IssueComponent.h"

class Decorator : public IssueComponent
{
protected:
    IssueComponent *component;

private:
    std::vector<IssueComponent *> getSnapshot() override;

public:
    Decorator(IssueComponent *component);

    Iterator *createIterator() override;
    void print() override;
    void printState() override;
    void execute() override;
    int getPriority() override;
};

#endif