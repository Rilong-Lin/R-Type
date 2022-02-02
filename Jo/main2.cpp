/*
** EPITECH PROJECT, 2021
** Jo
** File description:
** main2
*/

#include <SFML/Graphics.hpp>
#include "BasicBlock.hpp"
#include "GameBlock.hpp"
#include "Canva.hpp"

int main(int argc, char const *argv[])
{
    sf::RenderWindow win;
    win.create(sf::VideoMode::getDesktopMode(), "R_Type");
    //BasicDisplay d;
    //d = BasicDisplay("asset/bg.png");
    //Canva can(Vector2(60,34));
    //can.setBackGround({"asset/bg.png"});
    std::vector<GameActor> gA;
    BackGround bg({"asset/bg.png"});
    Player ps;
    gA.push_back(ps);
    //sf::Texture t;
    //t.loadFromFile("asset/bg.png");
    //sf::Sprite s(t);
    sf::Event e;
    //can.addPlayer(p);
//    can.play();
    /**/
    while (win.isOpen())
    {
        while (win.pollEvent(e))
            if (e.type == sf::Event::Closed
            || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                win.close();
        bg.drawBackground(win);
        //ps.display(win);
        for (GameActor p : gA) {
            p.tik();
            p.display(win);
        }
        
        //win.draw(d.sprites[0]);
        //d.display(win);
        win.display();
    }/**/
    return 0;
}
