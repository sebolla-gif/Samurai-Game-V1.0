#ifndef COMPONENTLIST_H_INCLUDED
#define COMPONENTLIST_H_INCLUDED

class Component {
public:
    virtual void update() = 0;
    virtual ~Component() = default;
};


struct Node {
    Component* component;
    Node* next;
};

class ComponentList {
private:
    Node* head;
    Node* tail;

public:
    ComponentList();
    ~ComponentList();
    void addComponent(Component* component);
    void removeComponent(Component* component);
    void clear();
    void updateComponents();
};


#endif // COMPONENTLIST_H_INCLUDED
