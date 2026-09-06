#ifndef OPEN_H
#define OPEN_H

#include "State.h"

class Open : public State
{
public:
    using State::State;

    void nextState() override;
};

#endif