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
    std::cout << "You just got invited to your first project in your intern year. This is a huge step up for you!" << std::endl;
    std::cout << "Firstly, you realise this company works on TaskForge to manage their project" << std::endl;
    std::cout << "Luckily TaskForge is easy to learn." << std::endl;

    std::cout << "Let's look at the current project on webdev." << std::endl;

    website->print(0);

    std::cout << std::endl << "Mm... quite an interesting structure of Issues. " << std::endl <<
        "Firstly, lets go depth first through the entire project until we get to Headings" << std::endl;
    std::cout << std::endl << "Creating DepthFirstIterator..." << std::endl;

    Iterator* DFSiterator = website->createIterator("DFS");

    while (DFSiterator->hasNext()) {

        if (DFSiterator->current()->getName() == "Headings") {
            std::cout << "Good we found it. Lets work on it!" << std::endl;
            DFSiterator->current()->execute();
            std::cout << "Check its state now!" << std::endl;
            DFSiterator->current()->print(0);

            std::cout << std::endl << "Lets try to complete it" << std::endl;;
            DFSiterator->current()->execute();

            std::cout << "If we messed up it will be set back to open, else it will be resolved" << std::endl;
            std::cout << "Now let's check the status" << std::endl;
            DFSiterator->current()->print(0);

            break;
        }

        std::cout << std::endl;
        DFSiterator->next();
        std::cout << std::endl;
    }

    std::cout << std::endl << "Structure after Scenario1" << std::endl;
    website->print(0);

    

    // End of Scenario 1
    std::cout << "=== Scenario 1 END ===" << std::endl << std::endl;

    // Start of Scenario 2
    std::cout << "=== Scenario 2 ===" << std::endl;

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
// add output for state changes and execution calls.
// add random for onFail() state change
// complete GDB section for pdf
