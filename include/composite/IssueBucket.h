#ifndef ISSUEBACKET_H
#define ISSUEBACKET_H

#include <vector>
#include <stack>
#include <string>

#include "../iterator/Iterator.h"
#include "./IssueComponent.h"

using namespace std;

class IssueBucket: public IssueComponent {

private:

string name;

vector<IssueComponent*> components;

//Function 1:
void getSnapshot(vector<IssueComponent*>& snapshot) override;

public:

//Function 2:
IssueBucket(string name);

//Function 3:
Iterator* createIterator(std::string type) override;

//Function 4:
void print(int level) override;

//Function 5:
void execute() override;

//Functin 6:
void addComponent(IssueComponent* component);

//Function 7:
void removeComponent(IssueComponent* component);

//Functin 8:
void printState() override;

//Function 9:
~IssueBucket();

};

#endif
