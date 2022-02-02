/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** GameBlock
*/

#include "GameBlock.hpp"
#include "MouvementTemplate.hpp"

void actPlayer(BasicEntities *actor)
{
        Player *p = (Player *)actor;
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                if (p->fireClock.tik())
                        p->map->push_back(new Missile(Vector2(p->getposition().x + 70, p->getposition().y + 20), 0));
}

void Player::changeRateOfFire(int change)
{
        rateOfFire += change;
        fireClock.setTikValue(rateOfFire);
}

Player::Player(int sp, int y_offset)
{
        if (sp == 0)
            setDisplay("asset/SpaceShip1.png", Vector2(3, 1), Vector2(96, 46), 4);
        position.x = 2 * 32;
        position.y = (10 + y_offset) * 32;
        Tag = "Player";
        mouve = localPlayerMouvemnt;
        act = actPlayer;
}
