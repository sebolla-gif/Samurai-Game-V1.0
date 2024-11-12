 #ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "characters.h"
#include "Enemy.h"

class Player : public Character, public Enemy
{
public:
    Player(const char*, int**,int, int,int,int,int,int);
    void update(float) override;
    void animation(int, int) override;
    void play() override;

    // Implementación de las funciones de la interfaz Enemy
    void attack(int x_player, int pos_y) override
    {
    if(x != x_player)
    {
        if((x_player - x) > 0)
        {
            state.walk = true;
            state.right = true;
        }
        else
        {
            state.walk = true;
            state.right = false;
        }
    }
    else
    {
        int numram = rand()%2;
        switch(numram)
        {
        case 0:
            state.attack_1 = true;
            break;
        case 1:
            //state.attack_2 = true;
            break;
        case 2:
            //state.attack_3 = true;
            break;
        default:
            break;
        }

    }
    return;
    }

    void takeDamage(int amount) override
    {
        // Lógica para reducir la salud del Samurai
        std::cout << "Samurai recibe " << amount << " de daño.\n";
        // Aquí podrías disminuir alguna variable de HP (vida)
    }
};


#endif // PLAYER_H_INCLUDED
