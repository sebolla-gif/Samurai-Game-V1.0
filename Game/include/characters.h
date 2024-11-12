#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED
#include "start.h"
#include "Entity.h"
#include "CombatComponent.h"
#include "MovementComponent.h"

class CombatComponent;
class MovementComponent;

extern BITMAP *buffer;

struct CharacterState
{
    bool run;
    bool right = true;
    bool walk = false;
    bool jump = false;
    bool attack_1=false;
    bool attack_2=false;
    bool attack_3=false;
    bool protection=false;
    bool hurt=false;
    bool continuous;

    bool isReadyForAction()
    {
        return !walk && !jump && !attack_1 && !attack_2 && !attack_3 && !continuous && !protection && !hurt;
    }
    bool isAttack()
    {
    return attack_1 || attack_2 || attack_3;
    }
};

class Character: public Entity {

public:

    const char* archive;
    int damage;
    int** dim;
    int pos;
    float speed;
    float vy; // Velocidad vertical
    float ay; // Aceleración vertical

    Character(const char* archive, int** dim, int x, int y, int width, int height, int damage, int speed)
        : Entity(x, y, width, height),archive(archive), damage(damage), dim(dim), pos(0),speed(speed), vy(0), ay(0)
    {
    }

    CharacterState state;
    BITMAP *character;

    MovementComponent* movementComponent;
    CombatComponent* combatComponent;

    virtual ~Character() {}  // Destructor virtual

};

#endif // CHARACTERS_H_INCLUDED
