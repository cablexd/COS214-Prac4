#include <vector>
#include <stack>
#include <string>
#include <iostream>
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/composite/IssueBucket.h"

using namespace std;

//Function 1:
vector<IssueComponent*> IssueBucket::getSnapshot(){

    return components;


}


//Function 2:
IssueBucket::IssueBucket(string name){

this->name = name;

}

//Function 3:
Iterator* IssueBucket::createIterator(){

return new DepthFirstIterator(this);

}



//Function 4:
void IssueBucket::print(int level) {

    cout << std::string(level * 2, ' ') << "Bucket: " << name << endl;

    for (auto* child : components)

        child->print();
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

for (auto* child : components)

        child->printState();
}


//Function 8:
IssueBucket::~IssueBucket(){

for (auto* c : components) 

delete c;


}