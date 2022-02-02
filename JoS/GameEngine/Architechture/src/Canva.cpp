/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Canva
*/

#include "Canva.hpp"

Canva::Canva(Vector2 size) : size(size)
{
    win.create(sf::VideoMode::getDesktopMode(), "R_Type");
    win.setFramerateLimit(60);
}

void Canva::checkDelete()
{
    //std::vector<std::vector<InteratibleObject *>::iterator> buff0;
    std::vector<std::vector<InteratibleObject *>::iterator> buff;
    std::vector<std::vector<GameActor *>::iterator> buff1;
    std::vector<std::vector<GameActor *>::iterator> buff2;
    

    //if (!objects2.empty())      
    //for (std::vector<InteratibleObject *>::iterator  i = objects2.begin(); i != objects2.end(); i++) 
    //    if ((*i)->deleteMe() && (*i)->deleteReady()){
    //        buff0.push_back(i);
    //    }
    //for (std::vector<InteratibleObject *>::iterator i : buff0){
    //        //delete *i;
    //        objects2.erase(i);
    //    }

    if (!objects.empty())      
    for (std::vector<InteratibleObject *>::iterator  i = objects.begin(); i != objects.end(); i++) 
        if ((*i)->deleteMe() && (*i)->deleteReady()){
            buff.push_back(i);
        }
    for (std::vector<InteratibleObject *>::iterator i : buff){
            delete *i;
            objects.erase(i);
        }

    if (!players.empty())      
    for (std::vector<GameActor *>::iterator  i = players.begin(); i != players.end(); i++) 
        if ((*i)->deleteMe() && (*i)->deleteReady()){
            buff1.push_back(i);
        }
    for (std::vector<GameActor *>::iterator i : buff1){
        delete *i;
        players.erase(i);
    }

    if (!enemys.empty())      
    for (std::vector<GameActor *>::iterator  i = enemys.begin(); i != enemys.end(); i++) 
        if ((*i)->deleteMe() && (*i)->deleteReady()){
            buff2.push_back(i);
        }
    for (std::vector<GameActor *>::iterator i : buff2){
        delete *i;
        enemys.erase(i);
    }
}

void Canva::tik()
{
    
    if (!tikClock.tik())
        return;
    bg.tik();
    for (GameActor *&p : players)
        p->tik(); 
    for (GameActor *&e : enemys)
        e->tik(); 
    for (InteratibleObject *&o : objects)
        o->tik();
    for (InteratibleObject *&o : objects2)
        o->tik();
    if (!objects.empty())    
    for (InteratibleObject *o : objects) {
        for (GameActor *p : players)
            if (!p->deleteMe())
            if (o->getSprites().getGlobalBounds().intersects(p->getSprites().getGlobalBounds())) {
                p->touchedBy(o->getTag());
                o->touchedBy(p->getTag());
            }
        for (GameActor *e : enemys)
            if (!e->deleteMe())
            if (o->getSprites().getGlobalBounds().intersects(e->getSprites().getGlobalBounds())) {
                e->touchedBy(o->getTag());
                o->touchedBy(e->getTag());
            }
    }
    checkDelete();
}

void Canva::display()
{
    bg.drawBackground(win);
    for (GameActor *e : enemys)
        if (!e->deleteMe())
            e->display(win);
    for (GameActor *p : players)
        if (!p->deleteMe())
            p->display(win);
    for (InteratibleObject *o : objects)
        if (!o->deleteMe())
            o->display(win);
    for (InteratibleObject *o : objects2)
        if (!o->deleteMe())
            o->display(win);
    win.display();
}

void Canva::play()
{ 
    sf::Event event;  
    
    while (win.isOpen())
    {
        while (win.pollEvent(event))
            if (event.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        tik();
        display();
    }
}

void Canva::setBgMusic(const std::string &s)
{
    bgmusic.setMusic(s);
    bgmusic.isRepeatable(true);
    bgmusic.play();
}

Canva::~Canva()
{
    for (GameActor *&p : players)
        delete p;
    for (GameActor *&e : enemys)
        delete e; 
    for (InteratibleObject *&o : objects)
        delete o;

}