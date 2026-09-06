#ifndef STATE_H
#define STATE_H

#include "../composite/IssueComponent.h"

class State
{
private:
    IssueComponent *component; // TODO: change to "Issue" after it's created

public:
    State(IssueComponent *component);
    virtual ~State();

    virtual void nextState() = 0;
};

#endif