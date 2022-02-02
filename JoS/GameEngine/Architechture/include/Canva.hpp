/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** Canva
*/

#ifndef CANVA_HPP_
#define CANVA_HPP_

#include "MyMusic.hpp"
#include "BasicBlock.hpp"
#include "GameBlock.hpp"

struct EnemyShell
{
    EnemyShell(Vector2 _refPosition, Vector2 oPosition, int id, int delay) :
    _refPosition(_refPosition),
    oPosition(oPosition),id(id), delay(delay){}
    Vector2 _refPosition;
    Vector2 oPosition;
    int id;
    int delay;
};

struct ObjectShell
{
    ObjectShell(Vector2 oPosition, int id) :
    oPosition(oPosition), id(id){}
    Vector2 oPosition;
    int id;
};

struct PlayerShell
{
    PlayerShell(Vector2 oPosition, int id) :
    oPosition(oPosition), id(id){}
    Vector2 oPosition;
    int id;
};

class GameShell {
    public:
        GameShell(Vector2 size);
        ~GameShell();
        void setBackGround(std::string s){bg = s;}
        void tik();
        //void addObjects(InteratibleObject *obj){objects.push_back(obj);};
        void addObjects(ObjectShell obj){objects2.push_back(obj);};
        void addPlayer(PlayerShell player){players.push_back(player);}; 
        void addEnemy(EnemyShell enem){enemys.push_back(enem);};
    protected:
    private:
        Vector2 size;
        std::string bg;
        std::vector<ObjectShell> objects;
        std::vector<ObjectShell> objects2;
        std::vector<PlayerShell> players;
        std::vector<EnemyShell> enemys;
        MyMusic bgmusic;
    
};

class Canva {
    public:
        Canva(Vector2 size);
        ~Canva();
        void setBackGround(std::vector<std::string> s){bg = BackGround(s);}
        void tik();
        void play();
        void display();
        //void addObjects(InteratibleObject *obj){objects.push_back(obj);};
        void addObjects(InteratibleObject *obj){objects2.push_back(obj);};
        void addPlayer(GameActor *player){ player->map = &objects; players.push_back(player);}; 
        void addEnemy(GameActor *enem){ enem->map = &objects ;enemys.push_back(enem);};
        void setBgMusic(const std::string &s);
        void checkDelete();
    protected:
    private:
        Tempo activeClock = Tempo(0);
        Tempo  tikClock= Tempo(1000/120);
        Tempo  displayClock= Tempo(1000/60); //Spupri
        Vector2 size;
        BackGround bg;
        sf::RenderWindow win;
        std::vector<InteratibleObject *> objects;
        std::vector<InteratibleObject *> objects2;
        std::vector<GameActor *> players;
        std::vector<GameActor *> enemys;
        MyMusic bgmusic;
    
};

#endif /* !CANVA_HPP_ */
