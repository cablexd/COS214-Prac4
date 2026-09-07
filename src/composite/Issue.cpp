#include <vector>
#include <string>
#include <iostream>
#include "../../include/state/State.h"
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"
#include "../../include/composite/Issue.h"

using namespace std;

void Issue::getSnapshot(vector<IssueComponent*>& snapshot) {
    return; // Do nothing
}

//Function 2:
Issue::Issue(string name){
    this->name = name;
}

void Issue::setState(State * state){
    if (this->state != nullptr)
    {
        delete this->state;
    }

    this->state = state;
}

//Function 3:
Iterator* Issue::createIterator(std::string type){
    vector<IssueComponent*> snapshot;
    snapshot.push_back(this);

    if (type == "priority") {
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    return new DepthFirstIterator(snapshot);
}

//Function 4:
void Issue::print(int level){
    cout << std::string(level * 2, ' ') << "Issue: " << name
        << " [" << state->getName() << "]" << endl; // or however State exposes its name
}

//Function 5:
void Issue::execute(){
    state->nextState();
}

//Functin 6:
void Issue::printState(){
    cout << name << " is currently: " << state->getName() << endl;
}

//Function 7:
Issue::~Issue(){
    delete state;
}
