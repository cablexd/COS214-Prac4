#include <iostream>

#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"
#include "../../include/state/Resolved.h"

InProgress::InProgress(Issue *issue) : State(issue, "In progress") {}

void InProgress::nextState()
{
    issue->setState(new Resolved(issue));
}

void InProgress::onFail()
{
    issue->setState(new Open(issue));
    // TODO: remove issue from parent bucket, wrap in PriorityDecorator, and add decorator back to bucket
}