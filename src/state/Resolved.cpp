#include <iostream>

#include "../../include/state/Resolved.h"

Resolved::Resolved(Issue *issue, IssueComponent *wrappedIssue) : State("Resolved", issue, wrappedIssue) {}

void Resolved::nextState()
{
    // do nothing
}