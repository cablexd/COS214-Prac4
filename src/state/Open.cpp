#include <iostream>

#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"

Open::Open(Issue *issue, IssueComponent *wrappedIssue) : State("Open", issue, wrappedIssue) {}

void Open::nextState()
{
    issue->setState(new InProgress(issue, wrappedIssue));
}