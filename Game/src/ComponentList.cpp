// ComponentList.cpp
#include "ComponentList.h"

ComponentList::ComponentList() : head(nullptr), tail(nullptr) {}

ComponentList::~ComponentList()
{
    clear();
}

void ComponentList::addComponent(Component* component)
{
    Node* newNode = new Node{component, nullptr};
    if (tail)
    {
        tail->next = newNode;
    }
    else
    {
        head = newNode;
    }
    tail = newNode;
}

void ComponentList::updateComponents()
{
    Node* current = head;
    while (current != nullptr)
    {
        current->component->update();
        current = current->next;
    }
}
void ComponentList::removeComponent(Component* component)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current)
    {
        if (current->component == component)
        {
            if (previous)
            {
                previous->next = current->next;
            }
            else
            {
                head = current->next;
            }
            if (current == tail)
            {
                tail = previous;
            }
            delete current->component;
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

void ComponentList::clear()
{
    Node* current = head;
    while (current)
    {
        Node* next = current->next;
        delete current->component; // Asumimos que Component tiene un destructor virtual
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
}
