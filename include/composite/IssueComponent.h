#ifndef ISSUECOMPONENT_H
#define ISSUECOMPONENT_H

#include <vector>
#include <stack>
#include <string>

class Decorator;
class Iterator;
class IssueBucket;

class IssueComponent
{
    friend class Decorator;   // allow decorator to call getSnapshot() on any component type
    friend class IssueBucket; // allow issue bucket to call getSnapshot() on any component type
    friend class Iterator;

protected:
    IssueComponent *parent;

private:
    virtual void getSnapshot(std::vector<IssueComponent *> &snapshot) = 0;

public:
    IssueComponent();
    virtual ~IssueComponent();

    virtual IssueBucket *getParentBucket(bool first = true) = 0;
    virtual IssueComponent *getHandle(bool first = true) = 0; // get topmost decorator of current component
    virtual Iterator *createIterator(std::string type) = 0;
    virtual void print(int level) = 0;
    virtual std::string getName() = 0;
    virtual void printState() = 0;
    virtual void execute() = 0;
    virtual int getPriority();
};

#endif
