#include <iostream>

#include "../../include/state/State.h"

State::State(Issue *issue, std::string name) : issue(issue), name(name) {}

std::string State::getName()
{
    return name;
}

State::~State()
{
    // empty
}