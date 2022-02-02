/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** music header
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>
#include <map>

class MyMusic {
    public:
        MyMusic(const std::string &m) ;
        MyMusic(const MyMusic &cp) : path(cp.path) {setMusic(cp.path);};
        const MyMusic& operator=(const MyMusic &cp)  {return cp;} //{path = cp.path; setMusic(cp.path);};
        MyMusic(){};
        ~MyMusic();

        void setMusic(const std::string &music);
        void play();
        void replay();
        void stop();
        void isRepeatable(bool);
        void setVolume(float);

    private:
        std::string path;
        sf::Music _music;
};

class MyMusicBox {
    public:
        MyMusicBox(){}
        ~MyMusicBox();
        void play(const std::string tag) {musicBox[tag]->play();}
        //void addSoud(std::string m, const std::string tag){musicBox[tag] = std::make_unique<MyMusic>(MyMusic(m));}
        void addSoud(std::string m, const std::string tag){musicBox[tag] = new MyMusic(m);}
    private:
        //std::map<std::string,std::unique_ptr<MyMusic>> musicBox;
        std::map<std::string,MyMusic *> musicBox;
};
#endif /* !MUSIC_HPP_ */
