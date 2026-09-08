#include <iostream>

#include "../../include/state/Resolved.h"

Resolved::Resolved(Issue *issue) : State("Resolved", issue) {}

void Resolved::nextState()
{
    // do nothing
}