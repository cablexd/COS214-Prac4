#ifndef ISSUEBACKET_H
#define ISSUEBACKET_H

#include <vector>
#include <stack>
#include <string>

#include "../iterator/Iterator.h"
#include "./IssueComponent.h"

using namespace std;

class IssueBucket{

private:

string name;

vector<IssueBucket*> components;

//Function 1:
vector<IssueComponent*>* getSnapshot();

public:

//Function 2:
IssueBucket(string name);

//Function 3:
Iterator* createIterator();

//Function 4:
void print(int level);

//Function 5:
void execute();

//Functin 6:
void addComponent(IssueComponent* component);

//Function 7:
void removeComponent(IssueComponent* component);

//Functin 8:
void printState();

//Function 9:
virtual ~IssueBucket();

};

#endif