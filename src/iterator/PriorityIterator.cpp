#include "../../include/iterator/PriorityIterator.h"
#include <algorithm>

PriorityIterator::PriorityIterator(vector<IssueComponent*> snapshot) {
    this->snapshot = snapshot;
    this->index = 0;
    this->filterAndSort();
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
void PriorityIterator::filterAndSort() {
    vector<IssueComponent*> filtered;

    // Filters snapshot for priority > 0
    for (IssueComponent* component : this->snapshot) {
        if (component->getPriority() > 0) {
            filtered.push_back(component);
        }
    }

    // Sorts priority but keeps original order for equal priorities
    std::stable_sort(filtered.begin(), filtered.end(), [](IssueComponent* a, IssueComponent* b) {
        return a->getPriority() > b->getPriority();
    });

    this->snapshot = filtered;
}

//Function 6:
PriorityIterator::~PriorityIterator() {
    this->snapshot.clear();
}
