/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** IEngine header
*/

#ifndef IENGINE_HPP_
#define IENGINE_HPP_

#include <SFML/System/Time.hpp>

class IEngine {
    public:
        virtual ~IEngine() = default;

        virtual void Init() = 0;
        virtual void processInput() = 0;
        virtual void Update(sf::Time) = 0;
        virtual void Draw() = 0;
        virtual void Pause() = 0;
        virtual void Start() = 0;

#endif /* !IENGINE_HPP_ */
