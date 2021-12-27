#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>

class Connection_Handler: public std::enable_shared_from_this<Connection_Handler>
{
    boost::asio::ip::tcp::socket socket_;
    const size_t msgLength{1024};
    char buffer[1024];
public:
    Connection_Handler(boost::asio::io_service& service_);
    boost::asio::ip::tcp::socket& getSocket();
    void start();
    void readHandle(const boost::system::error_code& err, size_t bytes_transferred);
    void writeHandle(const boost::system::error_code& err, size_t bytes_transferred);
    static std::shared_ptr<Connection_Handler> create(boost::asio::io_service& service_);
};
