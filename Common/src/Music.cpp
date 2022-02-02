/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** handle the music
*/

#include <MyMusic.hpp>
#include <iostream>

MyMusic::MyMusic(const std::string &music) : path(music)
{
    if (!_music.openFromFile(music))
        std::cout << "Error: cannot open music file : " << music << std::endl;
    _music.setLoop(false);
}

void MyMusic::setMusic(const std::string &music)
{
    path = music;
    if (!_music.openFromFile(music))
        std::cout << "Error: cannot open music file : " << music << std::endl;
    _music.setLoop(false);
}

MyMusic::~MyMusic()
{
    _music.stop();

}

void MyMusic::play()
{
    _music.play();
}

void MyMusic::stop()
{
    _music.stop();
}

void MyMusic::replay()
{
    _music.stop();
    _music.play();
}


void MyMusic::isRepeatable(bool rep)
{
    _music.setLoop(rep);
}

void MyMusic::setVolume(float volume)
{
    _music.setVolume(volume);
}

MyMusicBox::~MyMusicBox()
{
    //std::cerr << "Passing ~MusicBox\n";
    for(std::pair<std::string , MyMusic *> i : musicBox){
        i.second->stop();
        
        i.second->~MyMusic();
        //delete i.second;
    } 
    musicBox.clear();
}
