//server

#include <iostream>
#include "Server.h"
#include <boost/bind/bind.hpp>
#include "RequestClientAction.h"
#include "RequestGameState.h"
#include "ResponseListGames.h"
#include "Game.h"
#include "ClientActionEnum.h"


using boost::asio::ip::udp;

Server::Server()
{
    std::cout << "create server" << std::endl;
    gameEngine = Game();
}

void Server::run()
{


    while (true)
    {
        this->receive_client_action();
        this->send_game_state();
    }
}


void Server::init(int port)
{

    this->io_service = new boost::asio::io_context();
    this->socket = new udp::socket (*io_service, udp::endpoint(udp::v4(), 9999));

    this->endpoint = new udp::endpoint();

}

void Server::receive_client_action()
{
    RequestClientAction request;
    this->socket->receive_from(boost::asio::buffer(&request, sizeof(RequestClientAction)), *endpoint);

    int speed = 2;
    switch (request.action)
    {
        case ClientActionEnum::IDLE:
            std::cout << "IDLE" << std::endl;
            //TODO
            break;
        case ClientActionEnum::SHOOT:
            std::cout << "SHOOT" << std::endl;
            break;
            //Ajout TIR
        case ClientActionEnum::UP: {
            std::cout << "UP" << std::endl;
            //Ajout Déplacement
            break;
        }
        case ClientActionEnum::DOWN: {
            std::cout << "DOWN" << std::endl;
            //Ajout Déplacement
            break;
        }
        case ClientActionEnum::LEFT: {
            std::cout << "LEFT" << std::endl;
            //Ajout Déplacement
            break;
        }
        case ClientActionEnum::RIGHT:
            std::cout << "RIGHT" << std::endl;
            //Ajout Déplacement
            break;
    }
    // Check toute les entités et applique le déplacement si besoin a chaqu'un Cf : Monstre, Shoot, Obstacle

    //Retourne un vecteur
}

void Server::send_game_state()
{

    RequestGameState request;
//Prepare requete
    this-socket->send_to(boost::asio::buffer(&request, sizeof(RequestGameState)), *endpoint);
}

