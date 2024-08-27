#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED
#include "start.h"
#include "ComponentList.h"
#include "CombatComponent.h"
#include "MovementComponent.h"

class CombatComponent;
class MovementComponent;

extern BITMAP *buffer;

struct CharacterState
{
    bool run;
    bool right = true;
    bool walk;
    bool jump;
    bool bucle;
    bool attack_1=false;
    bool attack_2=false;
    bool attack_3=false;
    bool protection=false;
    bool hurt=false;
    bool continuous;

    bool isReadyForAction()
    {
        return !walk && !jump && !attack_1 && !attack_2 && !attack_3 &&
               !continuous && !protection && !hurt;
    }

};

class Character{
private:

    const char* archive;
    int height;
    int width;
    int damage;
    float vy; // Velocidad vertical
    float ay; // Aceleración vertical

public:

    Character(const char*, int**,int, int,int,int,int,int);
    ~Character();

    CharacterState state;
    ComponentList components;
    BITMAP *player;
    int** dim;
    int pos;
    int x,y;
    float speed;

    void animation(int,int);
    void update(float);
    void play();
    template<typename T>
    bool checkCollision(const T& other);
    int getx();
    int gety();

    MovementComponent* movementComponent;
    CombatComponent* combatComponent;

};

#endif // CHARACTERS_H_INCLUDED
