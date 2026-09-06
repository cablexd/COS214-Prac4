#include "../../include/Iterator/PriorityIterator.h"

PriorityIterator::PriorityIterator(vector<IssueComponent*> snapshot) {
    this->snapshot = snapshot;
    this->index = 0;
}

//Function 2:
bool PriorityIterator::hasNext() {
    if (this->index >= static_cast<int>(this->snapshot.size())) {
        return false;
    } else return true;
}

//Function 3:
void PriorityIterator::next() {
    this->index++;
}

//Function 4:
IssueComponent* PriorityIterator::current() {
    return this->snapshot[this->index];
}

//Function 5:
PriorityIterator::~PriorityIterator() {
    this->snapshot.clear();
}
