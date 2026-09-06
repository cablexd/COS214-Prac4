#include "../../include/Iterator/DepthFirstIterator.h"

DepthFirstIterator::DepthFirstIterator(vector<IssueComponent*> snapshot) {
    this->snapshot = snapshot;
    this->index = 0;
}

//Function 2:
bool DepthFirstIterator::hasNext() {
    if (this->index >= static_cast<int>(this->snapshot.size())) {
        return false;
    } else return true;
}

//Function 3:
void DepthFirstIterator::next() {
    this->index++;
}

//Function 4:
IssueComponent* DepthFirstIterator::current() {
    return this->snapshot[this->index];
}

//Function 5:
DepthFirstIterator::~DepthFirstIterator() {
    this->snapshot.clear();
}
