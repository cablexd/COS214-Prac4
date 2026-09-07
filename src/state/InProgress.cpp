#include <iostream>

#include "../../include/composite/IssueBucket.h"
#include "../../include/decorator/PriorityDecorator.h"
#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"
#include "../../include/state/Resolved.h"

InProgress::InProgress(Issue *issue, IssueComponent *wrappedIssue) : State("In progress", issue, wrappedIssue) {}

void InProgress::nextState()
{
    issue->setState(new Resolved(issue, wrappedIssue));
}

void InProgress::onFail()
{
    // increase issue priority by wrapping it in another PriorityDecorator
    IssueBucket *issueParent = wrappedIssue->getParent();
    issueParent->removeComponent(wrappedIssue);

    PriorityDecorator *decorator = new PriorityDecorator(wrappedIssue);
    issueParent->addComponent(decorator);

    issue->setState(new Open(issue, decorator)); // must be at the end of this function because this state gets deleted
}