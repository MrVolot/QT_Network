#include "server.h"


Server::Server(io_service &service):acceptor_{service, ip::tcp::endpoint(ip::tcp::v4(),10677)}
{
    startAccept();
}

void Server::handleAccept(std::shared_ptr<Connection_Handler> connection, const boost::system::error_code &err)
{
    if(!err){
        connection->start();
    }
    startAccept();
}

void Server::startAccept()
{
    std::shared_ptr<Connection_Handler> connection = Connection_Handler::create(acceptor_.get_executor().context());
    acceptor_.async_accept(connection->getSocket(), std::bind(&Server::handleAccept, this, connection,boost::asio::placeholders::error));
}
