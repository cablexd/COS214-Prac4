#include <iostream>

#include "../../include/state/State.h"

State::State(Component *component)
{
    this->component = component;
}

State::~State()
{
    // empty
}