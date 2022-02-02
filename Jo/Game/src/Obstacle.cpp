/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Obstacle
*/

#include "GameBlock.hpp"

void mouveObstacleLateral(BasicEntities *b)
{
    Obstacle *m = (Obstacle *) b;

    m->getposition().x -= m->getSpeed();
    if (m->getposition().x < -10)
        m->setDelete(true);
    
}

Obstacle::Obstacle(int id, int y)
{
    std::vector<std::string> paths = { "asset/ob1.png", "asset/ob2.png", "asset/ob3.png"};
    
    if (id < 3) {
        Tag = "Ob"  + std::to_string(id);
        setDisplay(paths[id], Vector2(2 , 2), Vector2(128, 104), 1);
    }
    if (id == 1)
        speed =  12;
    position = Vector2(2000, y);
    //anim.setTikValue(1000/16);
    mouve = mouveObstacleLateral;
}

