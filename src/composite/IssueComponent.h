#ifndef ISSUECOMPONENT_H
#define ISSUECOMPONENT_H

#include <vector>
#include <stack>
#include <string>
#include <Iterator.h>

using namespace std;

class Iterator;
class IssueComponent{

private:

virtual vector<IssueComponent*>* getSnapshot() = 0;

friend class Iterator;

public:

virtual Iterator* createIterator() = 0;

virtual void print() = 0;

virtual void printState() = 0;

virtual void execute() = 0;

virtual ~IssueComponent();

};

#endif