//characters.cpp
#include "characters.h"

Character::Character(const char* archive,int** dim,int x, int y,int height, int width, int speed, int damage)
    : archive(archive),height(height), width(width), damage(damage), vy(0), ay(0), dim(dim), pos(0), x(x), y(y),speed(speed)
{

    player = load_bitmap(archive, nullptr);
    movementComponent = new MovementComponent(this);
    combatComponent = new CombatComponent(this);
    components.addComponent(combatComponent);
    components.addComponent(movementComponent);
}

void Character::update(float GRAVITY)
{
    //Update
    components.updateComponents();

    //limites pantalla
    if(x>=VX-100)
        x=VX-100;
    if(x<=-36)
        x=-36;
    if(y >= VY-128)
        y=VY-128;
    if(y<=0)
        y=VY-128;

    //Gravity
    vy += ay; // Actualizar velocidad vertical
    y += vy;  // Actualizar posición vertical
    ay = GRAVITY; // Aplicar gravedad constante

    // Verificar límite superior de la pantalla
    if(y < 0)
    {
        y = 0;
        vy = 0; // Puedes poner vy a cero para detener el movimiento
    }

    // Verificar límite inferior de la pantalla
    if(y + height > VY)
    {
        y = VY - height;
        vy = 0; // Puedes poner vy a cero para detener el movimiento
    }
    return;
}

void Character::play()
{
    //walk
    if(!state.jump)
    {

        if(key[KEY_RIGHT])
        {
            state.walk = true;
            state.right = true;
        }
        if(key[KEY_LEFT])
        {
            state.walk = true;
            state.right = false;
        }
    }
    //run
    if(key[KEY_LSHIFT])
    {
        state.run = true;
        if (key[KEY_LSHIFT] && key[KEY_RIGHT])
        {
            state.walk = true;
            state.right = true;
        }

        if(key[KEY_LSHIFT] && key[KEY_LEFT])
        {
            state.walk = true;
            state.right = false;
        }

    }
    //jump
    if(key[KEY_SPACE])
    {
        if(y == (VY - height) && state.isReadyForAction())
        {
            state.jump = true;
            state.continuous = true;
        }

    }
    //attack 1
    if(key[KEY_J])  //10
    {
        state.attack_1 = true;
        state.continuous = true;
    }
    //attack 2
    if(key[KEY_K])
    {
        state.attack_2 = true;
        state.continuous = true;
    }
    //attack 3
    if(key[KEY_L])
    {
        state.attack_3 = true;
        state.continuous = true;
    }
    //protection
    if(key[KEY_H]){
        state.protection = true;
        state.continuous = true;
    }
    else{
        state.protection = false;
    }
    return;
}


void Character::animation(int a,int d)
{
    masked_blit(player,buffer, a*height,d*width, x, y, height,width);
    return;
}

template<typename T>
bool Character::checkCollision(const T& other)
{
    int left1 = x;
    int right1 = x + width;//
    int top1 = y;
    int bottom1 = y + height;

    int left2 = other.x;
    int right2 = other.x + other.width; //
    int top2 = other.y;
    int bottom2 = other.y + other.height;

    // Verificar si hay colisión
    if (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2)
    {
        // Hay colisión
        return true;
    }
    // No hay colisión
    return false;
}

int Character::getx()
{
    return x;
}
int Character::gety()
{
    return y;
}

Character::~Character()
{

}
