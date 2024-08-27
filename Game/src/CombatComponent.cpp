// CombatComponent.cpp
#include "CombatComponent.h"

void CombatComponent::update()
{
    // Lógica de actualización de combate
    attack1();
    attack2();
    attack3();
    protection();
    character->state.hurt = false;
}

void CombatComponent::attack1()
{

    int* row = character->dim[3];

    if(character->state.attack_1 && character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[0];
            character->state.attack_2 = false;
            character->state.attack_3 = false;
        }

        if(character->pos > row[1])
            character->pos=row[0];
        character->animation(character->pos,row[2]);
        character->state.attack_1 = true;
        character->pos++;
        if(character->pos > row[1])
        {
            character->state.attack_1 = false;
            character->state.continuous = true;
        }
    }
    if(character->state.attack_1 && !character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[4];
            character->state.attack_2 = false;
            character->state.attack_3 = false;
        }

        if(character->pos < row[3])
            character->pos=row[4];
        character->animation(character->pos,row[5]);
        character->state.attack_1 = true;
        character->pos--;
        if(character->pos < row[3])
        {
            character->state.attack_1 = false;
            character->state.continuous=true;
        }
    }
    return;
}

void CombatComponent::attack2()
{

    int* row = character->dim[4];

    if(character->state.attack_2 && character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[0];
            character->animation(character->pos,row[2]);
            character->state.attack_1 = false;
            character->state.attack_3 = false;
        }
        else
        {
            if(character->pos > row[1])
                character->pos=row[0];
            character->animation(character->pos,row[2]);
            character->state.attack_2 = true;
            character->x+=character->speed;
            character->pos++;
            if(character->pos > row[1])
            {
                character->state.attack_2 = false;
                character->state.continuous = true;
            }
        }
    }
    if(character->state.attack_2 && !character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[4];
            character->animation(character->pos,row[5]);
            character->state.attack_1 = false;
            character->state.attack_3 = false;
        }
        else
        {
            if(character->pos < row[3])
                character->pos=row[4];
            character->animation(character->pos,row[5]);
            character->state.attack_2 = true;
            character->x-=character->speed;
            character->pos--;
            if(character->pos < row[3])
            {
                character->state.attack_2 = false;
                character->state.continuous=true;
            }
        }
    }
    return;
}

void CombatComponent::attack3()
{

    int* row = character->dim[5];

    if(character->state.attack_3 && character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[0];
            character->animation(character->pos,row[2]);
            character->state.attack_1 = false;
            character->state.attack_2 = false;
        }
        else
        {
            if(character->pos > row[1])
                character->pos=row[0];
            character->animation(character->pos,row[2]);
            character->state.attack_3 = true;
            character->x+=character->speed;
            character->pos++;
            if(character->pos > row[1])
            {
                character->state.attack_3 = false;
                character->state.continuous = true;
            }
        }
    }
    if(character->state.attack_3 && !character->state.right && !character->state.walk && !character->state.protection)
    {
        character->state.jump = false;
        if(character->state.continuous)
        {
            character->pos=row[4];
            character->animation(character->pos,row[5]);
            character->state.attack_1 = false;
            character->state.attack_2 = false;
        }
        else
        {
            if(character->pos < row[3])
                character->pos=row[4];
            character->animation(character->pos,row[5]);
            character->state.attack_3 = true;
            character->x-=character->speed;
            character->pos--;
            if(character->pos < row[3])
            {
                character->state.attack_3 = false;
                character->state.continuous=true;
            }
        }


    }
    return;
}

bool CombatComponent::protection()
{

    int* row = character->dim[6];

    if(character->state.protection && character->state.right && !character->state.walk)
    {
        character->state.jump = false;
        character->state.attack_1 = false;
        character->state.attack_2 = false;
        character->state.attack_3 = false;
        if(character->state.continuous)
        {
            character->pos=row[0];
        }
        if(character->pos > row[1])
            character->pos = row[1];
        character->animation(character->pos, row[2]);
        character->pos++;
        return true;
    }
    if(character->state.protection && !character->state.right && !character->state.walk)
    {
        character->state.jump = false;
        character->state.attack_1 = false;
        character->state.attack_2 = false;
        character->state.attack_3 = false;
        if(character->state.continuous)
            character->pos=row[4];
        if(character->pos < row[3])
            character->pos = row[3];
        character->animation(character->pos, row[5]);
        character->pos--;
        return true;
    }
    return false;  // Asegúrate de devolver un valor por defecto si no se cumplen las condiciones anteriores
}

bool CombatComponent::hurt()
{

    int* row = character->dim[8];

    if(character->state.right == true)
    {
        if(character->pos > row[1])
            character->pos = row[0];
        character->animation(character->pos, row[2]);
        character->pos++;
        character->state.hurt = true;
        return true;
    }
    if(character->state.right == false)
    {
        if(character->pos > row[4])
            character->pos = row[3];
        character->animation(character->pos, row[5]);
        character->pos++;
        character->state.hurt = true;
        return true;
    }
    return false;  // Asegúrate de devolver un valor por defecto si no se cumplen las condiciones anteriores
}

void CombatComponent::dead()
{
    // Lógica de muerte
}

