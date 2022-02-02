/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** GameBlock
*/

#ifndef GAMEBLOCK_HPP_
#define GAMEBLOCK_HPP_

#include "BasicBlock.hpp"
#include "MouvementTemplate.hpp"
#include "MyMusic.hpp"

class Missile : public InteratibleObject {
    public:
        Missile(Vector2 _position, int id = 0);
        ~Missile(){}
        int &getSpeed(){return speed;}
        void setSpeed(int s){speed  = s;}
        void touchedBy(std::string s) override;
    protected:
    private:
        int speed = 6;

};

class Popups : public InteratibleObject {
    public:
        Popups();

    protected:
    private:
};

class Obstacle : public InteratibleObject {
    public:
        Obstacle(int id, int y = 500);
        int &getSpeed(){return speed;}
        ~Obstacle(){}
    protected:
    private:
        int speed = 15;
};

class Enemy : public GameActor {
    public:
        Enemy(Vector2 refPosition, Vector2 oPosition ,int id = 0, Tempo activeClock = Tempo(0));
        void touchedBy(std::string _tag) override;
        void tik() override;
    protected:
        Tempo activeClock;
        int life = 1;
        bool set = false;
    private:  
        
};

class Player : public GameActor {
    public:
        Player(int sp = 0, int x_offset = 0);
        Tempo fireClock = Tempo(500);
        void changeRateOfFire(int change); 
    private: 
        int rateOfFire = 500;
        float speed = 6;
};


#endif /* !GAMEBLOCK_HPP_ */
