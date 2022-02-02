/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** music header
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <iostream>

class Music {
    public:
        Music(const std::string &);
        ~Music();

        void play();
        void replay();
        void stop();
        void isRepeatable(bool);
        void setVolume(float);

    private:
        sf::Music _music;
};

#endif /* !MUSIC_HPP_ */
