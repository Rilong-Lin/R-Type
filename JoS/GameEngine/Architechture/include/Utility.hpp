/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Utility
*/

#ifndef UTIILTY_HPP_
#define UTIILTY_HPP_

#include "SFML/System/Clock.hpp"

class Tempo
{
    public:
        Tempo(float tikValue = 1000): tikValue(tikValue){}
        bool tik() {
            if (clock.getElapsedTime().asMilliseconds() > tikValue) {
                clock.restart();
                return true;
            }
            return false;
        }
        void setTikValue(int t){tikValue = t;}
    private:
        float tikValue; 
        sf::Time buffer;
        sf::Clock clock;
};

struct Vector2
{
    Vector2() {x = -1; y = -1;}
    Vector2(const Vector2& v){x = v.x; y = v.y;}
    Vector2(int _x, int _y) {
        x =_x;
        y = _y;
    }
    float x;
    float y;
};
#endif /* !UTILTY_HPP_ */
