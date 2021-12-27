#include "connection_handler.h"
#include <functional>
#include <iostream>
#include <memory>


Connection_Handler::Connection_Handler(boost::asio::io_service &service_): socket_{service_}{}

boost::asio::ip::tcp::socket &Connection_Handler::getSocket()
{
    return socket_;
}

void Connection_Handler::start()
{
    socket_.async_read_some(boost::asio::buffer(buffer, msgLength), boost::bind(&Connection_Handler::readHandle,
                                                                        shared_from_this(),
                                                                        boost::asio::placeholders::error,
                                                                        boost::asio::placeholders::bytes_transferred));

    socket_.async_write_some(boost::asio::buffer(buffer, msgLength), boost::bind(&Connection_Handler::writeHandle,
                                                                        shared_from_this(),
                                                                        boost::asio::placeholders::error,
                                                                        boost::asio::placeholders::bytes_transferred));
}

void Connection_Handler::readHandle(const boost::system::error_code &err, size_t bytes_transferred)
{
    if(err){
        std::cout<<"Error: "<<err.message()<<std::endl;
        socket_.close();
        return;
    }
    std::cout<<"Data: "<<buffer<<std::endl;
}

void Connection_Handler::writeHandle(const boost::system::error_code &err, size_t bytes_transferred)
{
    if(err){
        std::cout<<"Error: "<<err.message()<<std::endl;
        socket_.close();
        return;
    }
    std::cout<<"Message was sent\n";
}

std::shared_ptr<Connection_Handler> Connection_Handler::create(boost::asio::io_service& service_)
{
    return std::make_shared<Connection_Handler>(service_);
}
