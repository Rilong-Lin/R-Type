//client

#include <iostream>
#include <boost/asio.hpp>
#include <Request.h>
#include <Menu.hpp>
#include <Client.h>
#include <Mainframe.h>
#include <RequestClientAction.h>
#include <RequestGameState.h>
#include "ResponseListGames.h"

using boost::asio::ip::udp;


Client::Client()
{

}


void Client::run()
{
    Mainframe mainframe = Mainframe(this);
    mainframe.run();
}

void Client::init()
{

    try
    {
        /* init socket */
        this->io_service = new boost::asio::io_service();
        this->socket = new udp::socket(*io_service, udp::endpoint(udp::v4(), 0));
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}


void Client::get_state(ClientActionEnum action)
{
    /// Mettre le vecteur de basic
    try
    {
        RequestClientAction requestAction = {.action = action};
        size_t s = sizeof(RequestClientAction);

        udp::resolver resolver(*io_service);
        udp::resolver::query query(udp::v4(), "127.0.0.1", "9999");
        udp::endpoint server_endpoint = *resolver.resolve(query);

        this->socket->send_to(boost::asio::buffer((char *) &requestAction, s), server_endpoint);

        RequestGameState state;
        this->socket->receive_from(boost::asio::buffer((char *) &state, sizeof(RequestGameState)), server_endpoint);

       // Gerer Affichage

    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
/*
    return entities;*/
}
