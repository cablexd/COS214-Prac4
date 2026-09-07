#ifndef ISSUECOMPONENT_H
#define ISSUECOMPONENT_H

#include <vector>
#include <stack>
#include <string>

class Decorator;
class Iterator;

class IssueComponent
{
    friend class Decorator; // allow decorator to call getSnapshot() on any component type
    friend class IssueBucket; // allow issue bucket to call getSnapshot() on any component type
    friend class Iterator;

private:
    virtual void getSnapshot(std::vector<IssueComponent*>& snapshot) = 0;

public:
    virtual Iterator *createIterator(std::string type) = 0;

    virtual void print(int level) = 0;

    virtual void printState() = 0;

    virtual void execute() = 0;

    virtual int getPriority();

    virtual ~IssueComponent();
};

#endif
