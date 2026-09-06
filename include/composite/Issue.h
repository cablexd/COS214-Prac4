#ifndef ISSUE_H
#define ISSUE_H

#include <vector>
#include <stack>
#include <string>
#include <Iterator.h>
#include <IssueComponent.h>

using namespace std;

class State;
class Issue{

private:

string name;

State* state;

//Function 1:
vector<IssueComponent*>* getSnapshot(){return {};};

public:

//Function 2:
Issue(string name);

//Function 3:
Iterator* createIterator();

//Function 4:
void print(int level);

//Function 5:
void execute();

//Functin 6:
void printState();

//Function 7:
virtual ~Issue();

};

#endif