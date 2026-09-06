#ifndef PRIORITYITERATOR_H
#define PRIORITYITERATOR_H

#include <vector>
#include <stack>
#include <string>
#include "../composite/IssueComponent.h"
#include "Iterator.h"

using namespace std;

class PriorityIterator: public Iterator{

private:

vector<IssueComponent*> snapshot;

int index;

public:

//Function 1:
PriorityIterator(vector<IssueComponent*> snapshot);

//Function 2:
bool hasNext();

//Function 3:
void next();

//Function 4:
IssueComponent* current();

//Function 5:
~PriorityIterator();

};

#endif
