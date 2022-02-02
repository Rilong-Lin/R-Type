/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** handle the main menu
*/

#include "Menu.hpp"
#include <SFML/Window/Event.hpp>

Menu::Menu(float width, float height)
{
    if (!_font.loadFromFile("./rTypeSheet/leadcoat.ttf"))
        std::cout << "Error: no font." << std::endl;
    // Play button //
    _menu[0].setFont(_font);
    _menu[0].setFillColor(sf::Color::White);
    _menu[0].setString("Play");
    _menu[0].setCharacterSize(70);
    _menu[0].setPosition(400, 200);
    // Options button //
    _menu[1].setFont(_font);
    _menu[1].setFillColor(sf::Color::White);
    _menu[1].setString("Options");
    _menu[1].setCharacterSize(70);
    _menu[1].setPosition(400, 300);
    // About button //
    _menu[2].setFont(_font);
    _menu[2].setFillColor(sf::Color::White);
    _menu[2].setString("About");
    _menu[2].setCharacterSize(70);
    _menu[2].setPosition(400, 400);
    // Exit button //
    _menu[3].setFont(_font);
    _menu[3].setFillColor(sf::Color::White);
    _menu[3].setString("Exit");
    _menu[3].setCharacterSize(70);
    _menu[3].setPosition(400, 500);
}

Menu::~Menu()
{

}

void Menu::draw(sf::RenderWindow &w)
{
    for (int i = 0; i < LIST_MENU; i++)
        w.draw(_menu[i]);
}

void Menu::moveUp()
{
    if (mainMenuSelected - 1 >= 0) {
        _menu[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected--;
        if (mainMenuSelected == -1)
            mainMenuSelected = 2;
        _menu[mainMenuSelected].setFillColor(sf::Color::Blue);
    }
}

void Menu::moveDown()
{
    if (mainMenuSelected + 1 >= LIST_MENU) {
        _menu[mainMenuSelected].setFillColor(sf::Color::White);
        mainMenuSelected++;
        if (mainMenuSelected == 4)
            mainMenuSelected = 0;
        _menu[mainMenuSelected].setFillColor(sf::Color::Blue);
    }
}

int Menu::mainMenuPressed()
{
    return mainMenuSelected;
}
