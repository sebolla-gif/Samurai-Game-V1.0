// MovementComponent.cpp
#include "MovementComponent.h"

void MovementComponent::update()
{
    // Lógica de actualización de movimiento
    walk();
    run();
    jump();
    idle();
    character->state.walk = false;
    character->state.run = false;
    character->state.continuous = false;
}

void MovementComponent::idle()
{

    int* row = character->dim[0];

    if(character->state.right && character->state.isReadyForAction())
    {
        if(character->pos > row[1])
            character->pos = row[0];
        character->animation(character->pos, row[2]);
        character->pos++;
    }

    if(!character->state.right && character->state.isReadyForAction())
    {
        if(character->pos < row[3])
            character->pos = row[4];
        character->animation(character->pos, row[5]);
        character->pos--;
    }
    return;
}

void MovementComponent::walk()
{

    int* row = character->dim[1];

    if(!character->state.run)
    {

        if(character->state.walk && character->state.right && !character->state.jump)
        {
            character->x+=character->speed;
            if(character->pos > row[1])
                character->pos=row[0];
            character->animation(character->pos,row[2]);
            character->state.continuous=true;
            character->pos++;

        }
        if(character->state.walk && !character->state.right && !character->state.jump)
        {
            character->x-=character->speed;
            if(character->pos < row[3])
                character->pos = row[4];
            character->animation(character->pos,row[5]);
            character->state.continuous = true;
            character->pos--;

        }
    }
    return;
}

void MovementComponent::run()
{

    int* row = character->dim[2];

    if(character->state.run && !character->state.jump)
    {
        if (character->state.walk && character->state.right)
        {
            character->state.continuous = true;
            if(character->pos > row[1])
                character->pos = row[0];
            character->animation(character->pos,row[2]);
            character->pos++;
            character->x += (character->speed * 2);
        }
        if(character->state.walk && !character->state.right)
        {
            character->state.continuous = true;
            if(character->pos < row[3])
                character->pos = row[4];
            character->animation(character->pos,row[5]);
            character->pos--;
            character->x -=(character->speed * 2);
        }
    }
    return;
}

void MovementComponent::jump()
{

    int* row = character->dim[7];

    if(character->state.jump && character->state.right)
    {
        if(character->pos < row[0])
            character->pos = row[0];
        if(character->pos > row[1])
            character->pos=row[0];
        if(character->state.continuous)
            character->pos=row[0];
        if(character->pos > ((row[1] - row[0])/2)+row[0])
        {
            character->x+=30;
        }
        else
        {
            character->y-=60;
            character->x+=30;
        }
        character->animation(character->pos,row[2]);
        character->pos++;
        if(character->pos > row[1])
        {
            character->state.jump = false;
            character->state.continuous = true;
        }

    }
    if(character->state.jump && !character->state.right)
    {

        if(character->pos < row[3])
            character->pos = row[4];
        if(character->state.continuous)
            character->pos=row[4];
        if(character->pos < ((row[3] - row[4])/2)+row[4])
        {
            character->x-=30;
        }
        else
        {
            character->y-=60;
            character->x-=30;
        }
        character->animation(character->pos,row[5]);
        character->pos--;
        if(character->pos < row[3])
        {
            character->state.jump = false;
            character->state.continuous = true;
        }
    }
    return;
}

