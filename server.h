#pragma once
#include <boost/asio.hpp>
#include "connection_handler.h"

using namespace boost::asio;

class Server
{
    boost::asio::ip::tcp::acceptor acceptor_;

public:
    Server(boost::asio::io_service &service);
    void handleAccept(std::shared_ptr<Connection_Handler> connection, const boost::system::error_code& err);
    void startAccept();
};

