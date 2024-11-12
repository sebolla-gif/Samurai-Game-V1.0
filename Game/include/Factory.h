#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include "player.h"

enum Type {
    Samurai
    /*,
    Zombie,
    Alien,
    Robot
    */
};

class Factory {
public:
    static Player* crear(Type tipo, int** matrix_player_1) {
        switch(tipo) {
            case Type::Samurai:
                return new Player("player1.bmp", matrix_player_1, 100, VY - 128, 128, 128, 10, 25);//file,matrix,x,y,height,width,damage,speed
            /*
            case Type::Zombie:
                return new Zombie();
            case Type::Alien:
                return new Alien();
            case Type::Robot:
                return new Robot();
            */
            default:
                return nullptr;
        }
    }
};


#endif // FACTORY_H_INCLUDED
