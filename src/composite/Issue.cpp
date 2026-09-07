#include <vector>
#include <string>
#include <iostream>
#include "../../include/state/State.h"
#include "../../include/composite/Issue.h"
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"

using namespace std;

void Issue::getSnapshot(vector<IssueComponent *> &)
{
    // Do nothing
}

// Function 2:
Issue::Issue(string name)
{
    this->name = name;
}

// Function 3:
Iterator* Issue::createIterator(std::string type)
{
    std::vector<IssueComponent *> snapshot;
    snapshot.push_back(this);

    this->getSnapshot(snapshot);

    if (type == "priority")
    {
        std::cout << "Priority Iterator created" << std::endl;
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    std::cout << "DepthFirst Iterator created" << std::endl;
    return new DepthFirstIterator(snapshot);
}

void Issue::setState(State *state)
{
    if (this->state != nullptr)
    {
        delete this->state;
    }

    this->state = state;
}

// Function 4:
void Issue::print(int level)
{
    cout << std::string(level * 2, ' ') << "Issue: " << name
         << " [" << state->getName() << "]" << endl; // or however State exposes its name
}

// Function 5:
void Issue::execute()
{
    state->nextState();
}

// Functin 6:
void Issue::printState()
{
    cout << name << " is currently: " << state->getName() << endl;
}

// Function 7:
Issue::~Issue()
{
    delete state;
}
