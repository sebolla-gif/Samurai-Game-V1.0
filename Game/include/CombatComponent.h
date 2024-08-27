#ifndef COMBATCOMPONENT_H_INCLUDED
#define COMBATCOMPONENT_H_INCLUDED
#include "ComponentList.h"
#include "characters.h"

class Character;

class CombatComponent : public Component{
private:
    Character* character;
public:
    CombatComponent(Character* character) : character(character) {}
    void update() override;
    void attack1();
    void attack2();
    void attack3();
    bool protection();
    bool hurt();
    void dead();
};


#endif // COMBATCOMPONENT_H_INCLUDED
