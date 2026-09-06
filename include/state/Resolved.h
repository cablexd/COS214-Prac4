#ifndef RESOLVED_H
#define RESOLVED_H

#include "State.h"

class Resolved : public State
{
public:
    using State::State;

    void nextState() override;
};

#endif