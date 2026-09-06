#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "../../include/state/State.h"
#include "../../include/Iterator/DepthFirstIterator.h"
#include "../../include/composite/Issue.h"

using namespace std;


//Function 2:
Issue::Issue(string name){

this->name = name;

}

void Issue::setState(State * state){

  this->state = state; 
    
}

//Function 3:
Iterator* Issue::createIterator(){

return new DepthFirstIterator(this);
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