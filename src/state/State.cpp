#include <iostream>

#include "../../include/state/State.h"

State::State(std::string name, Issue *issue, IssueComponent *wrappedIssue) : name(name), issue(issue), wrappedIssue(wrappedIssue) {}

std::string State::getName()
{
    return name;
}

State::~State()
{
    // empty
}