#include "../../include/composite/IssueComponent.h"

IssueComponent::IssueComponent() : parent(nullptr) {}

IssueComponent::~IssueComponent() {}

IssueBucket *IssueComponent::getParent()
{
    return parent;
}

int IssueComponent::getPriority()
{
    return 0; // default implementation, overridden by PriorityDecorator
}
