#ifndef RESOLVED_H
#define RESOLVED_H

#include "State.h"

class Resolved : public State
{
public:
    Resolved(Issue *issue, IssueComponent *wrappedIssue);

    void nextState() override;
};

#endif