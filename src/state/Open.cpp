#include <iostream>

#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"

Open::Open(Issue *issue) : State("Open", issue) {}

void Open::nextState()
{
    issue->setState(new InProgress(issue));
}