/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** button header
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <iostream>
#include "IObject.hpp"

class Button: public IObject {
    public:
        Buttons(int, int, std::string, ObjectType);
        ~Button();

        ObjectType getType() override;
        sf::Sprite getSprite() override;
        sf::Text getText() override;
        void setText(char) override;

    private:
        ObjectType _type;
        float _buttonWidth;
        sf::Sprite _buttonImage;
        float _buttonHeight;
        sf::Text _playerText;
        sf::Texture _buttontexture;

#endif /* !BUTTON_HPP_ */
