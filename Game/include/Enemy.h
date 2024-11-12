#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

class Enemy {
public:
    virtual void attack(int x, int y) = 0;  // Funci�n pura, obliga a implementar "attack"
    virtual void takeDamage(int amount) = 0;  // Permite gestionar da�o recibido
    virtual ~Enemy() = default;  // Destructor virtual para evitar fugas de memoria
};

#endif // ENEMY_H_INCLUDED
