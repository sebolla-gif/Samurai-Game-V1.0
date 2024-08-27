#ifndef MOVEMENTCOMPONENT_H_INCLUDED
#define MOVEMENTCOMPONENT_H_INCLUDED
#include "ComponentList.h"
#include "characters.h"

class Character;

class MovementComponent : public Component{
private:
    Character* character;
public:
    MovementComponent(Character* character) : character(character) {}
    void update() override;
    void idle();
    void walk();
    void run();
    void jump();
};


#endif // MOVEMENTCOMPONENT_H_INCLUDED
