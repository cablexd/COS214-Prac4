#ifndef DEPTHFIRSTITERATOR_H
#define DEPTHFIRSTITERATOR_H

#include <vector>
#include <stack>
#include <string>
#include "../composite/IssueComponent.h"
#include "Iterator.h"


using namespace std;

class DepthFirstIterator : public Iterator{

private:

vector<IssueComponent*> snapshot;

int index;

public:

//Function 1:
DepthFirstIterator(vector<IssueComponent*> snapshot);

//Function 2:
bool hasNext();

//Function 3:
void next();

//Function 4:
IssueComponent* current();

//Function 5:
~DepthFirstIterator();

};
#endif
