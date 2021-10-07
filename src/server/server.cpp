/*
** EPITECH PROJECT, 2021
**
** File description:
**
*/

#include "server.hpp"

    Server::Server(asio::io_context &io_context)
    {
        this->acceptor_(io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), 4242));
        this->socket_(io_context);
    }

    Server::~Server()
    {
    }

    void Server::accept_()
    {
        this->acceptor_.accept(this->socket_);
    }

    void Server::send_(const std::string &message)
    {
        const std::string msg = message + "\n";
        asio::write(this->socket_, asio::buffer(message));
    }

    std::string Server::receive_()
    {
        asio::streambuf buf;
        asio::read_until(this->socket_, buf, "\n" );
        std::string data = asio::buffer_cast<const char*>(buf.data());
        return data;
    }
