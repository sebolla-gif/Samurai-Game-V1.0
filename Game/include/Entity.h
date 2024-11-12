#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "ComponentList.h"

class Entity {
public:
    // Propiedades básicas
    int x, y;            // Posición de la entidad
    int width, height;   // Dimensiones de la entidad
    float speedX, speedY; // Velocidad en ambos ejes
    ComponentList components; // Lista de componentes (Movimiento, Combate, etc.)

    // Constructor
    Entity(int x, int y, int width, int height)
        : x(x), y(y), width(width), height(height), speedX(0), speedY(0) {}

    // Destructor virtual
    virtual ~Entity() {}

    // Métodos virtuales para ser sobreescritos por clases derivadas
    virtual void update(float gravity) = 0;
    virtual void animation(int a, int d) = 0;
    virtual void play() = 0;

    // Método para verificar colisiones
    template<typename T>
    bool checkCollision(const T& other) {
        return !(x + width < other->x || x > other->x + other->width ||
                 y + height < other->y || y > other->y + other->height);
    }

    // Métodos adicionales para manipular la entidad
    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    void setSpeed(float newSpeedX, float newSpeedY) {
        speedX = newSpeedX;
        speedY = newSpeedY;
    }

    int getX() const { return x; }
    int getY() const { return y; }
};

#endif // ENTITY_H_INCLUDED
