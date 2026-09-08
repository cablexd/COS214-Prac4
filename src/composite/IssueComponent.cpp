#include "../../include/composite/IssueComponent.h"

IssueComponent::IssueComponent() : parent(nullptr) {}

IssueComponent::~IssueComponent() {}

int IssueComponent::getPriority()
{
    return 0; // default implementation, overridden by PriorityDecorator
}
