#ifndef STATE_H
#define STATE_H

#include "../composite/Component.h"

class State
{
private:
    Component *component;

public:
    State(Component *component);
    virtual ~State();

    virtual void nextState() = 0;
};

#endif