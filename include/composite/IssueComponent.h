#ifndef ISSUECOMPONENT_H
#define ISSUECOMPONENT_H

#include <vector>
#include <stack>
#include <string>

class Iterator;

class IssueComponent
{

private:
    virtual std::vector<IssueComponent *> *getSnapshot() = 0;

    friend class Iterator;

public:
    virtual Iterator *createIterator() = 0;

    virtual void print() = 0;

    virtual void printState() = 0;

    virtual void execute() = 0;

    virtual ~IssueComponent();
};

#endif