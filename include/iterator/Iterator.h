#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>
#include <stack>
#include <string>

#include "../composite/IssueComponent.h"

using namespace std;

class Iterator{

public:

//Function 1:
virtual bool hasNext() = 0;

//Function 2:
virtual void next() = 0;

//Function 3:
virtual IssueComponent* current() = 0;

//Function 4:
virtual ~Iterator();

};

#endif
