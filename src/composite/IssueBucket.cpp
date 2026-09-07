#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include "../../include/composite/IssueBucket.h"
#include "../../include/iterator/DepthFirstIterator.h"
#include "../../include/iterator/PriorityIterator.h"

using namespace std;

IssueBucket *IssueBucket::getParentBucket(bool first)
{
    if (!first)
        return this;
    return (parent == nullptr) ? nullptr : parent->getParentBucket(false);
}

IssueComponent *IssueBucket::getHandle(bool first)
{
    if (!first)
        return nullptr; // return null to indicate that the handle is below this node
    if (parent == nullptr)
        return this;
    IssueComponent *handle = parent->getHandle(false);
    return (handle == nullptr) ? this : handle;
}

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

// Function 3:
Iterator *IssueBucket::createIterator(std::string type)
{
    std::vector<IssueComponent *> snapshot;
    snapshot.push_back(this);

    this->getSnapshot(snapshot);

    if (type == "priority")
    {
        std::cout << "Priority Iterator created" << std::endl;
        return new PriorityIterator(snapshot);
    }

    // return DFS if not specified
    std::cout << "DepthFirst Iterator created" << std::endl;
    return new DepthFirstIterator(snapshot);
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
