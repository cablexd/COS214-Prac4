#include <vector>
#include <string>
#include <iostream>
#include "../../include/iterator/Iterator.h"
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"

using namespace std;

Iterator* IssueComponent::createIterator(std::string type) {
    std::vector<IssueComponent*> snapshot;
    snapshot.push_back(this);

    this->getSnapshot(snapshot);


    if (type == "priority") {
        std::cout << "Priority Iterator created" << std::endl;
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    std::cout << "DepthFirst Iterator created" << std::endl;
    return new DepthFirstIterator(snapshot);

}

IssueComponent::~IssueComponent(){

// empty

}
