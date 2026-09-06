#ifndef STATE_H
#define STATE_H

#include "../composite/Issue.h"

class State
{
private:
    Issue *issue;
    std::string name;

public:
    State(Issue *issue, std::string name);
    virtual ~State();

    std::string getName();
    virtual void nextState() = 0;
};

#endif