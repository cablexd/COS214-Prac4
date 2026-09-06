#ifndef PRIORITYTITERATOR_H
#define PRIORITYITERATOR_H

#include <vector>
#include <stack>
#include <string>
#include "IssueComponent.h"
#include "Iterator.h"

using namespace std;

class PriorityIterator{

private:

stack<IssueComponent*> stack;

public:

//Function 1:
PriorityIterator();

//Function 2:
bool hasNext();

//Function 3:
void next();

//Function 4:
IssueComponent* current();

//Function 5:
virtual ~PriorityIterator();

};

#endif