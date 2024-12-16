#ifndef WEBSOCKET_SERVER_H
#define WEBSOCKET_SERVER_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <memory>
#include <string>

namespace beast = boost::beast; // For HTTP and WebSocket
namespace asio = boost::asio;  // For Asynchronous I/O
using tcp = asio::ip::tcp;     // For TCP sockets

class WebSocketServer {
public:
    WebSocketServer(asio::io_context& ioc, tcp::endpoint endpoint);
    void run(); // Start the server

private:
    void accept(); // Accept new connections
    void handleSession(tcp::socket socket); // Handle client sessions

    asio::io_context& ioc_;
    tcp::acceptor acceptor_;
};

#endif // WEBSOCKET_SERVER_H
