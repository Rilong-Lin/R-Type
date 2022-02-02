/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** handle the button
*/

#include <Button.hpp>

Button::Button(const std::string &spr)
{
    _x = 0;
    _y = 0;
    _life = 3;
    _playerTexture.loadFromFile(spr);
    _playerSize = (sf::Vector2f)_playerTexture.getSize();
    _playerShape.setTexture(&_playerTexture);
    _playerShape.setSize(_playerSize);
    _playerSprite.setTexture(_playerTexture);
}

Button::~Button()
{

}
