#ifndef OPEN_H
#define OPEN_H

#include "State.h"

class Open : public State
{
public:
    Open(Issue *issue);

    void nextState() override;
};

#endif