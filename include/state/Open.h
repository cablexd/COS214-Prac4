#ifndef OPEN_H
#define OPEN_H

#include "State.h"

class Open : public State
{
public:
    Open(Issue *issue, IssueComponent *wrappedIssue);

    void nextState() override;
};

#endif