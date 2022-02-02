/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** MouvementTemplate
*/

#include "MouvementTemplate.hpp"
#include <SFML/Graphics.hpp>
#include "math.h"

#define PI 3.14159265

void CircularBackAnForth(BasicEntities *b)
{
    GameActor *g = (GameActor *) b;
    Vector2 &position = b->getposition();
    Vector2 &keyPos = g->getRefPos();
    double &offset = g->getCircularOffset();
    static int ad = -1;

    position.x  = keyPos.x + (cos(offset * PI / 180.0 ) * 40);
    position.y  = keyPos.y + (sin(offset * PI / 180.0 ) * 40);
    offset += 1;
    keyPos.x += ad; 
    if (keyPos.x < 300)
        keyPos.x = 300;
    if (offset > 360) {
        ad *= -1;
        offset  = 0;
    }
}

void Circular(BasicEntities *b)
{
    GameActor *g = (GameActor *) b;
    Vector2 &position = b->getposition();
    Vector2 &keyPos = g->getRefPos();
    double &offset = g->getCircularOffset();
    
    position.x  = keyPos.x + (cos(offset * PI / 180.0 ) * 40);
    position.y  = keyPos.y + (sin(offset * PI / 180.0 ) * 40);
    offset += 1;
    if (offset > 360)
        offset  = 0;
}

void localPlayerMouvemnt(BasicEntities *b)
{
     Vector2 &position = b->getposition();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            position.y -= 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            position.x -= 4;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            position.y += 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            position.x += 2;
}
