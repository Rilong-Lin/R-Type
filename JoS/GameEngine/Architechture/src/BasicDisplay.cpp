/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** BasicDisplay
*/

#include "BasicDisplay.hpp"
//#include <iostream>

BasicDisplay::BasicDisplay(std::string path_ressourse, Vector2 hint, Vector2 rectFrame, int nbOfFrame ) : size_hint(hint) ,rectFrame(rectFrame), nbOfFrame(nbOfFrame){
    printf("BasicConstructor path %s rect %f\n",path_ressourse.c_str() , rectFrame.x);
    text.loadFromFile(path_ressourse);
    text.setRepeated(true);
    if (rectFrame.x == -1)
        sprites.push_back(sf::Sprite(text));
    else {
        sf::IntRect rec(0, 0,rectFrame.x, rectFrame.y);
        for (int i = 0; i < nbOfFrame; i++) {
            sf::Sprite buff(text);
            buff.setTextureRect(rec);
            rec.left += rectFrame.x;
            buff.setPosition(-500, -500);
            sprites.push_back(buff);
           
        }
    }
    set = true;
}


void BasicDisplay::setDisplay(std::string path_ressourse, Vector2 _hint, Vector2 _rectFrame, int _nbOfFrame ) 
{
    size_hint = Vector2(_hint);
    rectFrame = Vector2(_rectFrame);
    nbOfFrame = _nbOfFrame;
    text.loadFromFile(path_ressourse);
    index = 0;
    text.setRepeated(true);
    if (rectFrame.x == -1)
        sprites.push_back(sf::Sprite(text));
    else {
        sf::IntRect rec(0, 0,rectFrame.x, rectFrame.y);
        for (int i = 0; i < nbOfFrame; i++) {
          //  printf("rec x %d\n",   rectFrame.x );
            sf::Sprite buff(text);
            buff.setTextureRect(rec);
            rec.left += rectFrame.x;
            buff.setPosition(-500, -500);
            sprites.push_back(buff);
           
        }
    }
    set = true;
    printf("SetDis path %s %f, nb of sprtit %d\n",path_ressourse.c_str() , rectFrame.x , sprites.size());
}

BasicDisplay &BasicDisplay::operator=(const BasicDisplay & cp)
{
    size_hint = Vector2(cp.getSizeHint().x, cp.getSizeHint().y);
    rectFrame = cp.getRectFrame();
    nbOfFrame = cp.nbOfFrame;
    text = cp.getTexture();
    text.setRepeated(true);
    if (rectFrame.x == -1)
        sprites.push_back(sf::Sprite(text));
    else {
        sf::IntRect rec(0, 0,rectFrame.x, rectFrame.y);
        for (int i = 0; i < nbOfFrame; i++) {
            sf::Sprite buff(text);
            buff.setTextureRect(rec);
            rec.left += rectFrame.x;
            sprites.push_back(buff);
        }
    }
    set = cp.set;
    return *this;
}

BasicDisplay::BasicDisplay(const BasicDisplay &cp)
{
    size_hint = Vector2(cp.getSizeHint().x, cp.getSizeHint().y);
    rectFrame = cp.getRectFrame();
    text = cp.getTexture();
    nbOfFrame = cp.nbOfFrame;
    //sprites = cp.sprites;
    //printf("cp  %f\n", rectFrame.x);
    if (rectFrame.x == -1)
        sprites.push_back(sf::Sprite(text));
    else {
        sf::IntRect rec(0, 0, (int) rectFrame.x,(int) rectFrame.y);
        for (int i = 0; i < nbOfFrame; i++) {
            sf::Sprite buff(text);
            buff.setTextureRect(rec);
            rec.left += rectFrame.x;
            //buff.setPosition(cp.sprites[i].getPosition());
            //printf("cp y  %f\n",cp.sprites[i].getPosition().y );
            sprites.push_back(buff);
        }
    }
    set = cp.set;
}

void BasicDisplay::changeSpriteIndex()
{
    index = (index == sprites.size() -1) ? 0 : index + 1;
}
void BasicDisplay::display(sf::RenderWindow &win)
{
    //printf("dispal %f \n", getSprites().getPosition().y);
    //if (rectFrame.x != -1)
    //    sprites[0].setTextureRect(sf::IntRect(0, 0,rectFrame.x, rectFrame.y));
    
    win.draw(getSprites());
}

void  BackGround::tik()
{
    //sf::Vector2()
    if (clock.tik()) {
        sf::Vector2f  v = display[index].getSprites().getPosition();
        v.x -= 1;
        display[index].getSprites().setPosition(v);
    }
}

void  BackGround::drawBackground(sf::RenderWindow &win)
{
    display[index].display(win);
}

BackGround::BackGround(std::vector<std::string> path)
{
    for (std::string p : path) {
        display.push_back(BasicDisplay(p));
        scrolling.push_back(false);
    }
}
