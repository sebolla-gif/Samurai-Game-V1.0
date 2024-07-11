#ifndef CHARACTERS_H_INCLUDED
#define CHARACTERS_H_INCLUDED
#include "start.h"

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
    bool isNotWalking()
    {
        return walk;
    }
    bool isNotJumping()
    {
        return jump;
    }
    bool isNotAttacking()
    {
        return attack_1 && attack_2 && attack_3;
    }
    bool isNotBusy()
    {
        return continuous && protection && hurt;
    }
};

class Character{
private:
    const char* archive;
    int** dim;
    int x,y;
    int pos;
    int height;
    int width;
    float speed;
    int damage;
    float vy; // Velocidad vertical
    float ay; // Aceleraci�n vertical
    CharacterState state;
public:
    Character(const char*, int**,int, int,int,int,int,int);
    BITMAP *player;
    ~Character();
    void play();
    void animation(int,int);
    void idle();
    void Walk();
    void Run();
    void Attack_1();
    void Attack_2();
    void Attack_3();
    bool Protection();
    void Jump();
    bool Hurt();
    void dead();
    void update();
    template<typename T>
    bool checkCollision(const T& other);
    int getx();
    int gety();
    bool get_bool(int);

};

#endif // CHARACTERS_H_INCLUDED


