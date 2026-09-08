#include <iostream>
#include <random>

#include "../../include/composite/IssueBucket.h"
#include "../../include/decorator/PriorityDecorator.h"
#include "../../include/state/Open.h"
#include "../../include/state/InProgress.h"
#include "../../include/state/Resolved.h"

InProgress::InProgress(Issue *issue) : State("In progress", issue) {}

void InProgress::nextState()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // 50/50 probability
    std::bernoulli_distribution coinFlip(0.5);

    // Roll the result
    bool success = coinFlip(gen);

    if (success) {
        std::cout << "Success! Issue is now Resolved" << std::endl;
        issue->setState(new Resolved(issue));
    } else {
        std::cout << "Execute failed! Priority of Issue increased! Issue is now set to OPEN" << std::endl;
        this->onFail();
    }
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
