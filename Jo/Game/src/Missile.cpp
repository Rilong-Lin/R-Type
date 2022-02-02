/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Missile
*/

#include "GameBlock.hpp"
#include "MyMusic.hpp"

void mouveMissileLateral(BasicEntities *b)
{
    Missile *m = (Missile *) b;

    m->getposition().x += m->getSpeed();
    if (m->getposition().x > 2000)
        m->setDelete(true);
    
}

Missile::Missile(Vector2 _position, int id)
{
    std::vector<std::string> paths = { "asset/missile/miss0.png", "asset/missile/miss1.png", "asset/missile/miss2.png"};
    
    if (id < 3) {
        Tag = "PMissile"  + std::to_string(id);
        setDisplay(paths[id], Vector2(2 , 1), Vector2(89, 33), 4);
    }
    if (id == 1)
        speed =  12;
    position = _position;
    anim.setTikValue(1000/16);
    mouve = mouveMissileLateral;
    //creation.setMyMusic("asset/sound/laser0.ogg");
    //creation.play();  
    mbox.addSoud("asset/sound/laser0.ogg", "creation");
    mbox.play("creation");
}

void Missile::touchedBy(std::string _tag)
{
    if (Tag.substr(0,8) == "PMissile")
        if (_tag.substr(0, 5) == "Enemy"){
             setDelete(true);
        }
}