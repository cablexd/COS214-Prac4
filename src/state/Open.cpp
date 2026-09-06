#include <iostream>

#include "../../include/state/Open.h"

Open::Open(Issue *issue) : State(issue, "Open") {}

void Open::nextState()
{
    // TODO
}