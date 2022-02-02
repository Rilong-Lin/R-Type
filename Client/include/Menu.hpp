/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** menu header
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>

#define LIST_MENU 4

class Menu {
    public:
        Menu(float, float);
        ~Menu();

        void draw(sf::RenderWindow &);
        void moveUp();
        void moveDown();
        int mainMenuPressed();

    private:
        int mainMenuSelected;
        sf::Font _font;
        sf::Text _menu[LIST_MENU];
};

#endif /* !MENU_HPP_ */
