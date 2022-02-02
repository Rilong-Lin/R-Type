/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** BasicEntities
*/

#include "BasicBlock.hpp"


void BasicEntities::tik()
{
    if (act)
        act(this);
    if (mouve)
        mouve(this);
    if (anim.tik())
        changeSpriteIndex();
    getSprites().setPosition(position.x , position.y);
}

BasicEntities::BasicEntities(const BasicEntities &cp) : BasicDisplay(cp) , position(cp.position)
{
    displayClock = cp.displayClock;
    Tag = cp.Tag;
    mouve = cp.mouve;
    
}