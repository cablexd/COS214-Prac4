#include <iostream>
#include "include/composite/IssueBucket.h"
#include "include/composite/Issue.h"
#include "include/decorator/LanguageDecorator.h"
#include "include/decorator/PriorityDecorator.h"

int main()
{
    // Creation of Scenario 1
    IssueBucket* website = new IssueBucket("WebsiteCreation");
    IssueBucket* frontend = new IssueBucket("FrontEnd");
    IssueBucket* backend = new IssueBucket("BackEnd");

    website->addComponent(frontend);
    website->addComponent(backend);

    IssueBucket* functionality = new IssueBucket("Functionality");
    IssueComponent* functions = new PriorityDecorator(new Issue("Functions"));

    IssueComponent* buttons = new Issue("Buttons");
    IssueComponent* headings = new Issue("Headings");
    IssueComponent* decoratedAuthCheck = new LanguageDecorator("JavaScript", new Issue("Identity_Authentication"));

    frontend->addComponent(buttons);
    frontend->addComponent(headings);
    frontend->addComponent(functionality);
    functionality->addComponent(functions);

    backend->addComponent(decoratedAuthCheck);

    std::cout << "=== Scenario 1 ===" << std::endl;

    website->print(0);

    std::cout << std::endl << "Creating DepthFirstIterator..." << std::endl;

    Iterator* DFSiterator = website->createIterator("DFS");

    while (DFSiterator->hasNext()) {
        std::cout << "Current: " << DFSiterator->current()->getName();
        std::cout << std::endl;
        DFSiterator->next();
    }

    std::cout << std::endl << "Creating PriorityIterator..." << std::endl;
    Iterator* PriorityIterator = website->createIterator("priority");

    website->execute();

    std::cout << std::endl << "Iterating through PriorityIterator..." << std::endl;
    while (PriorityIterator->hasNext()) {
        std::cout << "Current: " << PriorityIterator->current()->getName() << std::endl;;
        PriorityIterator->current()->execute();
        std::cout << PriorityIterator->current()->getName() << std::endl;;
        PriorityIterator->next();
    }

    delete website;
    delete DFSiterator;
    delete PriorityIterator;

    return 0;
}

// TODO:
// add string getName() for Component and concretes
// add output for state changes and execution calls.
// add random for onFail() state change
// complete GDB section for pdf
