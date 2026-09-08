#ifndef DECORATOR_H
#define DECORATOR_H

#include "../composite/IssueComponent.h"

class Decorator : public IssueComponent
{
protected:
    IssueComponent *component;

private:
    void getSnapshot(std::vector<IssueComponent *> &snapshot) override;

public:
    Decorator(IssueComponent *component);

    IssueBucket *getParentBucket(bool first) override;
    IssueComponent *getHandle(bool first) override;
    Iterator *createIterator(std::string type) override;
    void print(int level) override;
    void printState() override;
    void execute() override;
    int getPriority() override;
};

#endif
