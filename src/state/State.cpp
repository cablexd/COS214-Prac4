#include <iostream>

#include "../../include/state/State.h"

State::State(std::string name, Issue *issue) : issue(issue), name(name) {}

State::~State() {}

std::string State::getName()
{
    return name;
}