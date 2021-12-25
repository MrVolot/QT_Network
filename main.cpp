#include <boost/asio.hpp>
#include <iostream>
#include "server.h"
using namespace boost::asio;
using ip::tcp;

std::string read(tcp::socket& sckt){
    boost::asio::streambuf buffer;
    boost::asio::read_until(sckt, buffer,"\n");
    std::string str{boost::asio::buffer_cast<const char*>(buffer.data())};
    return str;
}

void send(const std::string& msg, tcp::socket& sckt){
    const std::string sendMessage = msg + "\n";
    boost::asio::write(sckt, boost::asio::buffer(sendMessage));
}

int main()
{
  //  Server server;
    boost::asio::io_service io_service;

    tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 10677 ));


    tcp::socket socket_(io_service);
    acceptor_.accept(socket_);
    while(true){

        std::string str{read(socket_)};
        std::cout<<str;
        send(str, socket_);
    }
}
