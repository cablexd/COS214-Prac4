#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include <vector>
#include <stack>
#include <string>
#include "IssueComponent.h"
#include "Iterator.h"


using namespace std;

class DepthFirstIterator{

private:

stack<IssueComponent*> stack;

public:

//Function 1:
DepthFirstIterator();

//Function 2:
bool hasNext();

//Function 3:
void next();

//Function 4:
IssueComponent* current();

//Function 5:
virtual ~DepthFirstIterator();

};
#endif