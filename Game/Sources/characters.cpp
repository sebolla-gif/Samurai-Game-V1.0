//characters.cpp
#include "characters.h"

Character::Character(const char* _archive,int** date,int _x, int _y,int _height, int _width, int _speed, int _damage)
{
    dim = date;
    width = _width;
    height = _height;
    speed = _speed;
    damage = _damage;
    archive = _archive;
    player = load_bitmap(archive, nullptr);
    x = _x;
    y = _y;
    pos = 0;
    vy = 0;
    ay = 0;
}

void Character::play()
{
    state.continuous=false;
    state.walk = false;
    Walk();
    state.run = false;
    Run();
    Attack_1();
    Attack_2();
    Attack_3();
    state.protection=false;
    Protection();
    Jump();
    idle();
    state.hurt=false;
    //limites pantalla
    if(x>=VX-100)
        x=VX-100;
    if(x<=-36)
        x=-36;
    if(y >= VY-128)
        y=VY-128;
    if(y<=0)
        y=VY-128;
    return;
}
void Character::idle()
{
    int value1, value2, value3, value4, value5, value6;
    if (dim != nullptr)
    {
        int* row = dim[0];

        value1 = row[0];
        value2 = row[1];
        value3 = row[2];
        value4 = row[3];
        value5 = row[4];
        value6 = row[5];
    }
    if(state.right && state.isReadyForAction())
    {
        if(pos > value2)
            pos = value1;
        animation(pos, value3);
        pos++;
    }

    if(state.right == false && state.isReadyForAction())
    {
        if(pos > value5)
            pos = value4;
        if(pos < value4)
            pos = value4;
        animation(pos, value6);
        pos++;
    }
    return;
}
void Character::Walk()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[1];

        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if(state.run == false)
    {
        if(key[KEY_LEFT] && key[KEY_RIGHT])
        {
            state.walk=false;
            idle();
        }
        else
        {
            if(key[KEY_RIGHT] && state.jump == false)
            {
                x+=speed;
                if(pos > row_right_end)
                    pos=row_right_init;
                animation(pos,col_right);
                state.walk = true;
                state.right = true;
                state.continuous=true;
                pos++;

            }
            if(key[KEY_LEFT] && state.jump == false)
            {
                x-=speed;
                if(pos < row_left_init)
                    pos = row_left_init;
                if(pos > row_left_end)
                    pos = row_left_init, y=VY-128;
                animation(pos,col_left);
                state.walk = true;
                state.right = false;
                state.continuous = true;
                pos++;

            }
        }
    }
    return;
}
void Character::Run()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[2];

        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if(key[KEY_LSHIFT])
    {
        state.run = true;
        if (key[KEY_LSHIFT] && key[KEY_RIGHT])
        {
            state.walk = true;
            state.right = true;
            state.continuous = true;
            if(pos > row_right_end)
                pos=row_right_init;
            animation(pos,col_right);
            pos++;
            x+=(speed+40);
        }
        if(key[KEY_LSHIFT] && key[KEY_LEFT])
        {
            state.walk = true;
            state.right = false;
            state.continuous = true;
            if(pos < row_left_init)
                pos=row_left_init;
            if(pos > row_left_end)
                pos=row_left_init;
            animation(pos,col_left);
            pos++;
            x-=(speed+40);
        }
    }
    return;
}
void Character::Attack_1()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[3];
        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if((key[KEY_J] || state.attack_1 == true) && state.attack_2 == false && state.right == true && state.walk == false && state.attack_3 == false && state.protection==false)
    {
        if(state.attack_1 == false)
            pos=row_right_init, state.attack_2 = false, state.attack_3 = false;
        if(pos > row_right_end)
            pos=row_right_init;
        animation(pos,col_right);
        pos++;
        state.attack_1 = true;
        state.continuous=true;
        if(pos > row_right_end)
        {
            state.attack_1 = false;
        }
    }
    if((key[KEY_J] || state.attack_1 == true) && state.attack_2 == false && state.right == false && state.walk == false && state.attack_3 == false && state.protection==false)
    {
        if(state.attack_1 == false)
            pos=row_left_init, state.attack_2=false, state.attack_3 = false;
        if(pos > row_left_end)
            pos=row_left_init;
        animation(pos,col_left);
        pos++;
        state.attack_1 = true;
        state.continuous=true;
        if(pos > row_left_end)
        {
            state.attack_1 = false;
        }
    }
    return;
}
void Character::Attack_2()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[4];
        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if((key[KEY_K] || state.attack_2 == true) && state.attack_1 == false && state.right == true && state.walk == false && state.attack_3 == false && state.protection==false)
    {
        if(state.attack_2 == false)
            pos=row_right_init, state.attack_1=false, state.attack_3 = false;
        if(pos > row_right_end)
            pos=row_right_init;
        animation(pos,col_right);
        pos++;
        x+=speed;
        state.continuous=true;
        state.attack_2 = true;
        if(pos > row_right_end)
        {
            state.attack_2 = false;
        }
    }
    if((key[KEY_K] || state.attack_2 == true) && state.attack_1 == false && state.right == false && state.walk == false && state.attack_3 == false && state.protection==false)
    {
        if(state.attack_2 == false)
            pos=row_left_init, state.attack_1=false, state.attack_3 = false;
        if(pos > row_left_end)
            pos=row_left_init;
        animation(pos,col_left);
        pos++;
        x-=speed;
        state.continuous=true;
        state.attack_2 = true;
        if(pos > row_left_end)
        {
            state.attack_2 = false;
        }
    }
    return;
}
void Character::Attack_3()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[5];
        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if((key[KEY_L] || state.attack_3 == true) && state.attack_1 == false && state.right == true && state.walk == false && state.attack_2 == false && state.protection==false)
    {
        if(state.attack_3 == false)
            pos=row_right_init, state.attack_1=false, state.attack_2=false;
        if(pos > row_right_end)
            pos=row_right_init;
        animation(pos,col_right);
        pos++;
        x+=speed;
        state.continuous=true;
        state.attack_3 = true;
        if(pos > row_right_end)
        {
            state.attack_3 = false;
        }
    }
    if((key[KEY_L] || state.attack_3 == true) && state.attack_1 == false && state.right == false && state.walk == false && state.attack_2 == false && state.protection==false)
    {
        if(state.attack_3 == false)
            pos=row_left_init, state.attack_1=false, state.attack_2=false;
        if(pos > row_left_end)
            pos=row_left_init;
        animation(pos,col_left);
        pos++;
        x-=speed;
        state.continuous=true;
        state.attack_3 = true;
        if(pos > row_left_end)
        {
            state.attack_3 = false;
        }
    }
    return;
}

bool Character::Protection()
{
    int row_right_end, col_right,row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[6];
        row_right_end = row[1];
        col_right = row[2];
        row_left_end = row[4];
        col_left = row[5];
    }
    if(key[KEY_H] && state.right == true && state.walk == false)
    {
        if(pos > row_right_end)
            pos = row_right_end;
        animation(pos, col_right);
        pos++;
        state.protection = true;
        state.continuous = true;
        return true;
    }
    if(key[KEY_H] && state.right == false && state.walk == false)
    {
        if(pos > row_left_end)
            pos = row_left_end;
        animation(pos, col_left);
        pos++;
        state.protection = true;
        state.continuous = true;
        return true;
    }
    return false;  // Aseg�rate de devolver un valor por defecto si no se cumplen las condiciones anteriores
}
void Character::Jump()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[7];
        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if((key[KEY_SPACE] || state.jump == true) && state.right == true)
    {
        if(state.jump==false)
            pos=row_right_init;
        if(pos > row_right_end)
            pos=row_right_init;
        if(pos < ((row_right_end - row_right_init)/2)+row_right_init)
        {
            if(state.walk == true)
            {
                y-=40;
            }
            else
            {
                y-=35;
            }
        }
        animation(pos,col_right);
        pos++;
        state.jump = true;
        state.continuous = true;
        if(pos > row_right_end)
            state.jump = false;
    }
    if((key[KEY_SPACE] || state.jump == true) && state.right == false)
    {
        if(state.jump==false)
            pos=row_left_init;
        if(pos > row_left_end)
            pos=row_left_init;
        if(pos < (((row_left_end - row_left_init)/2)+row_left_init))
            y-=70;
        animation(pos,col_left);
        pos++;
        state.jump = true;
        state.continuous = true;
        if(pos > row_left_end)
            state.jump = false;
    }
    return;
}
bool Character::Hurt()
{
    int row_right_init, row_right_end, col_right, row_left_init, row_left_end, col_left;
    if (dim != nullptr)
    {
        int* row = dim[8];
        row_right_init = row[0];
        row_right_end = row[1];
        col_right = row[2];
        row_left_init = row[3];
        row_left_end = row[4];
        col_left = row[5];
    }
    if(state.right == true)
    {
        if(pos > row_right_end)
            pos = row_right_init;
        animation(pos, col_right);
        pos++;
        state.hurt = true;
        return true;
    }
    if(state.right == false)
    {
        if(pos > row_left_end)
            pos = row_left_init;
        animation(pos, col_left);
        pos++;
        state.hurt = true;
        return true;
    }
    return false;  // Aseg�rate de devolver un valor por defecto si no se cumplen las condiciones anteriores
}


void Character::animation(int a,int d)
{
    //stretch_blit(player, buffer, a*height, d*width, player->w, player->h, x, y, SCREEN_W, SCREEN_H);
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

    // Verificar si hay colisi�n
    if (right1 >= left2 && left1 <= right2 && bottom1 >= top2 && top1 <= bottom2)
    {
        // Hay colisi�n
        return true;
    }
    // No hay colisi�n
    return false;
}
void Character::update()
{
    vy += ay; // Actualizar velocidad vertical
    y += vy;  // Actualizar posici�n vertical
    ay = GRAVITY; // Aplicar gravedad constante

    // Verificar l�mite superior de la pantalla
    if(y < 0)
    {
        y = 0;
        vy = 0; // Puedes poner vy a cero para detener el movimiento
    }

    // Verificar l�mite inferior de la pantalla
    if(y + height > VY)
    {
        y = VY - height;
        vy = 0; // Puedes poner vy a cero para detener el movimiento
    }
    return;
}
int Character::getx()
{
    return x;
}
int Character::gety()
{
    return y;
}
bool Character::get_bool(int _value)
{
    switch(_value)
    {
    case 1:
        return state.attack_1;
    case 2:
        return state.attack_2;
    case 3:
        return state.attack_3;
    default:
        return false;  // Aseg�rate de devolver un valor por defecto si no se cumplen los casos anteriores
    }
}


Character::~Character()
{

}
