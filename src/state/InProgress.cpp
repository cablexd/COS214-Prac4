#include <iostream>

#include "../../include/composite/IssueBucket.h"
#include "../../include/decorator/PriorityDecorator.h"
#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"
#include "../../include/state/Resolved.h"

InProgress::InProgress(Issue *issue) : State("In progress", issue) {}

void InProgress::nextState()
{
    issue->setState(new Resolved(issue));
}

void InProgress::onFail()
{
    // increase issue priority by wrapping it in another PriorityDecorator
    IssueComponent *handle = issue->getHandle();
    IssueBucket *issueParent = handle->getParentBucket();
    issueParent->removeComponent(handle);

    PriorityDecorator *decorator = new PriorityDecorator(handle);
    issueParent->addComponent(decorator);

    issue->setState(new Open(issue)); // must be at the end of this function because this state gets deleted
}