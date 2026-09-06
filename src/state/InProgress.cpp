#include <iostream>

#include "../../include/state/InProgress.h"

InProgress::InProgress(Issue *issue) : State(issue, "In progress") {}

void InProgress::nextState()
{
    // TODO
}

void InProgress::onFail()
{
    // TODO: set state to open and wrap in another priority decorator
}