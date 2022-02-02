/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** BasicBlock
*/

#ifndef BASICBLOCK_HPP_
#define BASICBLOCK_HPP_
#include "Utility.hpp"
#include "BasicDisplay.hpp"
#include "MyMusic.hpp"


//
class BasicDisplay
{
    public:
        BasicDisplay(): size_hint(-1,-1){set= false;}
        BasicDisplay(std::string path_ressourse,
        Vector2 hint = Vector2(1, 1), Vector2 rectFrame = Vector2(-1, -1), int nbOfFrame = 1);
        BasicDisplay(const BasicDisplay &cp);
        BasicDisplay &operator=(const BasicDisplay &);
        void setDisplay(std::string path_ressourse, Vector2 hint = Vector2(1, 1), Vector2 rectFrame = Vector2(-1, -1), int nbOfFrame = 1);
        void display(sf::RenderWindow &win);
        void changeSpriteIndex();
        bool set;
        Vector2 getSizeHint() const {return size_hint;}
        sf::Texture getTexture() const {return text;}
        Vector2 getRectFrame() const {return rectFrame;}
        int getNbOfFrame() const {return nbOfFrame;}
        sf::Sprite &getSprites()
        { if (sprites.size() > index)return sprites[index]; else printf("error sprites empty");exit(84);}
    private:
        std::vector<sf::Sprite> sprites;
        Vector2 rectFrame;
        int nbOfFrame;
        sf::Texture text;
        int index = 0;
        std::vector<int> frame_limite;
        Vector2 size_hint;
};


class BackGround {
    public:
        BackGround(){set = false;}
        //~BackGround(){};
        BackGround(std::vector<std::string> path);
        void setScrolling(std::vector<bool> src){scrolling = src;}
        void drawBackground(sf::RenderWindow &win);
        bool set;
        void tik();
        std::vector<BasicDisplay> display;
    protected:
    private:
        Tempo clock = Tempo(1000/5);
        int index = 0;
        std::vector<bool> scrolling;
};

//
class BasicEntities : public BasicDisplay
{
    public:
        BasicEntities(){};
        BasicEntities(const BasicEntities &cp);
        ~BasicEntities(){}
        Vector2 &getposition(){return position;}
        virtual void tik();
        virtual void touchedBy(std::string Tag){}
        void (*mouve)(BasicEntities *_this) = nullptr;
        void (*act)(BasicEntities *actor) = nullptr;
        std::string getTag(){return Tag;}
        bool deleteMe() {return del;}
        void setDelete(bool b){del = b;}
        bool deleteReady(){return deteleteDelay.tik();}
    protected:
        Tempo deteleteDelay = Tempo(0);
        MyMusicBox mbox;
        bool del = false;
        Tempo displayClock = Tempo(1000/4);
        std::string Tag = "";
        Vector2 position;
        Tempo anim = Tempo(1000/4);
};



class InteratibleObject : public  BasicEntities{
    public:
        InteratibleObject(){};
        //~InteratibleObject(){printf("iii\n");}
    protected:
    private:
        bool destrutible;
};

class GameActor : public BasicEntities {
    public:
        GameActor(){};
        GameActor(const GameActor &cp) : BasicEntities(cp){}
        virtual void onContact(std::string tag){};
        std::vector<InteratibleObject *> *map;
        Vector2 &getRefPos(){return refPosition;}
        double &getCircularOffset(){return circularoffset;}
    protected:
        double circularoffset = std::rand() % 360; 
        Vector2 refPosition;
    private: 
};


/*

*/
#endif /* !BASICBLOCK_HPP_ */
