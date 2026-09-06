#ifndef IN_PROGRESS_H
#define IN_PROGRESS_H

#include "State.h"

class InProgress : public State
{
public:
    using State::State;

    void nextState() override;
    void onFail(); // state-specific method
};

#endif