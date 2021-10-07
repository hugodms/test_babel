/*
** EPITECH PROJECT, 2021
**
** File description:
**
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <asio.hpp>

    class Server
    {
        public:
        // all function for my class ---->
            Server(asio::io_context &);
            ~Server();

            Server(Server const &) noexcept = default;
            Server(Server &&) noexcept = default;
            Server &operator=(Server const &) noexcept = default;
            Server &operator=(Server &&r) noexcept = default;

        // all function for my project ---->
            void accept_();
            void send_(const std::string &);
            std::string receive_();

        protected:
        private:
            asio::ip::tcp::socket socket_;
            asio::ip::tcp::acceptor acceptor_;
    };

#endif /*SERVER_HPP*/
