#ifndef STATE_H
#define STATE_H

#include "../composite/Issue.h"

class State
{
protected:
    Issue *issue;
    IssueComponent *wrappedIssue; // can be wrapped with decorators

private:
    std::string name;

public:
    State(std::string name, Issue *issue, IssueComponent *wrappedIssue);
    virtual ~State();

    std::string getName();
    virtual void nextState() = 0;
};

#endif