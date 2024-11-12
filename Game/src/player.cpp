#include "Player.h"

Player::Player(const char* archive,int** dim, int x, int y, int height, int width,int speed, int damage)
    :Character(archive, dim, x, y, height, width, speed, damage)
{
    character = load_bitmap(archive, nullptr);
    if (!character)
    {
        allegro_message("Error loading bitmap");
    }
    components = ComponentList();
    movementComponent = new MovementComponent(this);
    combatComponent = new CombatComponent(this);
    components.addComponent(combatComponent);
    components.addComponent(movementComponent);

}

void Player::update(float GRAVITY)
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
void Player::animation(int a, int d)
{
    masked_blit(character,buffer, a*height,d*width, x, y, height,width);
    return;
}

void Player::play()
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
    if(key[KEY_H])
    {
        state.protection = true;
        state.continuous = true;
    }
    else
    {
        state.protection = false;
    }
    return;
}


