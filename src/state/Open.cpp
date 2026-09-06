#include <iostream>

#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"

Open::Open(Issue *issue) : State(issue, "Open") {}

void Open::nextState()
{
    issue->setState(new InProgress(issue));
}