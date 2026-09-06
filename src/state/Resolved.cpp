#include <iostream>

#include "../../include/state/Resolved.h"

Resolved::Resolved(Issue *issue) : State(issue, "Resolved") {}

void Resolved::nextState()
{
    // do nothing
}