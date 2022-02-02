/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** main
*/

#include "GameBlock.hpp"
#include "Canva.hpp"

int main(int argc, char const *argv[])
{
    Canva canva(Vector2(60, 34));
    Tempo t(3000);
    canva.setBackGround({"asset/bg.png"});
    canva.setBgMusic("asset/instru.ogg");
    //canva.addObjects(new Obstacle(0));
    //canva.addObjects(new Obstacle(1, 300));
    //canva.addObjects(new Obstacle(2 , 800));
    canva.addPlayer(new Player());
    canva.addEnemy( new Enemy(Vector2(40 * 32, 120) ,Vector2(60 *32, 120), 1));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 320) ,Vector2(60 *32, 520), 0));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 520) ,Vector2(60 *32, 520), 1));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 720) ,Vector2(60 *32, 520), 0));

    canva.addEnemy( new Enemy(Vector2(40 * 32, 120) ,Vector2(60 *32, 120), 1, Tempo(5000)));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 320) ,Vector2(60 *32, 520), 0, Tempo(5000)));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 520) ,Vector2(60 *32, 520), 1, Tempo(5000)));
    canva.addEnemy( new Enemy(Vector2(40 * 32, 720) ,Vector2(60 *32, 520), 0, Tempo(5000)));
 
    
    ////canva.addPlayer(std::make_unique<Player>(Player()));
    //canva.addEnemy(std::make_unique<Enemy>(Enemy(Vector2(40 * 32, 120) ,Vector2(60 *32, 120), 1)));
    //canva.addEnemy(std::make_unique<Enemy>(Enemy(Vector2(40 * 32, 320) ,Vector2(60 *32, 520), 0)));
    //canva.addEnemy(std::make_unique<Enemy>(Enemy(Vector2(40 * 32, 520) ,Vector2(60 *32, 520), 1)));
    //canva.addEnemy(std::make_unique<Enemy>(Enemy(Vector2(40 * 32, 720) ,Vector2(60 *32, 520), 0)));
    //p.display(canva.win);
    //canva.addObjects(new Missile(Vector2(100, 100)));
    canva.play();

    return 0;
}
