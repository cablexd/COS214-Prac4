#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"
#include "../../include/composite/IssueBucket.h"

using namespace std;

//Function 1:
void IssueBucket::getSnapshot(vector<IssueComponent*>& snapshot) {
    for (auto* component : components) {
        snapshot.push_back(component);
        component->getSnapshot(snapshot);
    }
}


//Function 2:
IssueBucket::IssueBucket(string name){

this->name = name;

}

//Function 3:
Iterator* IssueBucket::createIterator(std::string type){
    std::vector<IssueComponent*> snapshot;
    snapshot.push_back(this);

    for (auto* component : components) {
        component->getSnapshot(snapshot);
    }


    if (type == "priority") {
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    return new DepthFirstIterator(snapshot);
}



//Function 4:
void IssueBucket::print(int level) {

    cout << std::string(level * 2, ' ') << "Bucket: " << name << endl;

    for (auto* child : components)
    {
        child->print(level + 1);
    }
}


//Function 5:
void IssueBucket::execute(){

    for(auto* child: components){

        child->execute();
    }

}

//Functin 6:
void IssueBucket::addComponent(IssueComponent* component){
    components.push_back(component);
}

void IssueBucket::removeComponent(IssueComponent* component) {
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

//Functin 7:
void IssueBucket::printState(){
    for (auto* child : components)  child->printState();
}


//Function 8:
IssueBucket::~IssueBucket(){
    for (auto* c : components) delete c;
}
