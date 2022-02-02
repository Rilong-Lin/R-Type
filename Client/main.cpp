/*
** EPITECH PROJECT, 2021
** B-CPP-501-PAR-5-1-rtype-jonathan.layduhur
** File description:
** test my sfml main (Rilong)
*/

#include <Menu.hpp>

int main()
{
    sf::RenderWindow _Menu(sf::VideoMode(960, 720), "Main", sf::Style::Default);
    Menu mainMenu(_Menu.getSize().x, _Menu.getSize().y);

    while (_Menu.isOpen()) {
        sf::Event event;
        while (_Menu.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _Menu.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    mainMenu.moveUp();
                    break;
                }
                if (event.key.code == sf::Keyboard::Down) {
                    mainMenu.moveDown();
                    break;
                }
                if (event.key.code == sf::Keyboard::Return) {
                    sf::RenderWindow Play(sf::VideoMode(960, 720), "GAME");
                    sf::RenderWindow Options(sf::VideoMode(960, 720), "OPTIONS");
                    sf::RenderWindow About(sf::VideoMode(960, 720), "ABOUT");
                    int x = mainMenu.mainMenuPressed();

                    if (x == 0) {
                        while (Play.isOpen()) {
                            sf::Event aevent;
                            while (Play.pollEvent(aevent)) {
                                if (aevent.type == sf::Event::Closed)
                                    Play.close();
                                if (aevent.type == sf::Event::KeyPressed) {
                                    if (aevent.key.code == sf::Keyboard::Escape)
                                        Play.close();
                                }
                            }
                            Options.close();
                            About.close();
                            Play.clear();
                            Play.display();
                        }
                    }
                    if (x == 1) {
                        while (Options.isOpen()) {
                            sf::Event aevent;
                            while (Options.pollEvent(aevent)) {
                                if (aevent.type == sf::Event::Closed)
                                    Options.close();
                                if (aevent.type == sf::Event::KeyPressed) {
                                    if (aevent.key.code == sf::Keyboard::Escape)
                                        Options.close();
                                }
                            }
                            Play.close();
                            Options.clear();
                            About.close();
                            Options.display();
                        }
                    }
                    if (x == 2) {
                        while (About.isOpen()) {
                            sf::Event aevent;
                            while (About.pollEvent(aevent)) {
                                if (aevent.type == sf::Event::Closed)
                                    About.close();
                                if (aevent.type == sf::Event::KeyPressed) {
                                    if (aevent.key.code == sf::Keyboard::Escape)
                                        About.close();
                                }
                            }
                            Play.close();
                            Options.clear();
                            About.clear();
                            About.display();
                        }
                    }
                    if (x == 3)
                        _Menu.close();
                    break;
                }
            }
        }
        _Menu.clear();
        mainMenu.draw(_Menu);
        _Menu.display();
    }
}
