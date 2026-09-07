#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "../../include/composite/IssueBucket.h"

using namespace std;

// Function 1:
void IssueBucket::getSnapshot(vector<IssueComponent *> &snapshot)
{
    for (auto *component : components)
    {
        snapshot.push_back(component);
        component->getSnapshot(snapshot);
    }
}

// Function 2:
IssueBucket::IssueBucket(string name)
{
    this->name = name;
}

// Function 4:
void IssueBucket::print(int level)
{

    cout << std::string(level * 2, ' ') << "Bucket: " << name << endl;

    for (auto *child : components)
    {
        child->print(level + 1);
    }
}

// Function 5:
void IssueBucket::execute()
{
    for (auto *child : components)
        child->execute();
}

// Functin 6:
void IssueBucket::addComponent(IssueComponent *component)
{
    if (component->parent != nullptr)
        throw "Component already has a parent!";

    components.push_back(component);
    component->parent = this;
}

void IssueBucket::removeComponent(IssueComponent *component)
{
    components.erase(std::remove(components.begin(), components.end(), component), components.end());
    component->parent = nullptr;
}

// Functin 7:
void IssueBucket::printState()
{
    for (auto *child : components)
        child->printState();
}

// Function 8:
IssueBucket::~IssueBucket()
{
    for (auto *c : components)
        delete c;
}
