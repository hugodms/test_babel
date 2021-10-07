/*
** EPITECH PROJECT, 2021
** Babel
** File description:
** program entry-point
*/

#include "server.hpp"

    int main()
    {
        asio::io_context io_context;
        Server server_(io_context);
        server_.accept_();

        std::string message = server_.receive_();
        std::cout << message;

        server_.send_("Hello From Server!");
        std::cout << "Servent sent Hello message to Client!" << std::endl;

        return (42);
    }
