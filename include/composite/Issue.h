#ifndef ISSUE_H
#define ISSUE_H

#include <vector>
#include <stack>
#include <string>

#include "./IssueComponent.h"
#include "../iterator/Iterator.h"

using namespace std;

class State;
class Issue : public IssueComponent
{

private:
    string name;

    State *state;

    // Function 1:
    void getSnapshot(vector<IssueComponent *> &snapshot) override;

public:
    // Function 2:
    Issue(string name);

    void setState(State *state);

    // Function 4:
    void print(int level) override;

    // Function 5:
    void execute() override;

    // Functin 6:
    void printState() override;

    // Function 7:
    virtual ~Issue();
};

#endif
