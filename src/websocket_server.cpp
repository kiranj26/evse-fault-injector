#include "websocket_server.h"
#include <boost/asio/strand.hpp>
#include <iostream>

WebSocketServer::WebSocketServer(asio::io_context& ioc, tcp::endpoint endpoint)
    : ioc_(ioc), acceptor_(asio::make_strand(ioc)) {
    // Open the acceptor
    beast::error_code ec;
    acceptor_.open(endpoint.protocol(), ec);
    if (ec) {
        std::cerr << "Open error: " << ec.message() << std::endl;
        return;
    }

    // Bind to the server address
    acceptor_.bind(endpoint, ec);
    if (ec) {
        std::cerr << "Bind error: " << ec.message() << std::endl;
        return;
    }

    // Start listening for connections
    acceptor_.listen(asio::socket_base::max_listen_connections, ec);
    if (ec) {
        std::cerr << "Listen error: " << ec.message() << std::endl;
        return;
    }
}

void WebSocketServer::run() {
    accept();
}

void WebSocketServer::accept() {
    // Asynchronously accept a new connection
    acceptor_.async_accept(
        asio::make_strand(ioc_),
        [this](beast::error_code ec, tcp::socket socket) {
            if (ec) {
                std::cerr << "Accept error: " << ec.message() << std::endl;
            } else {
                // Handle the new connection
                handleSession(std::move(socket));
            }

            // Accept another connection
            accept();
        });
}

void WebSocketServer::handleSession(tcp::socket socket) {
    // Create a shared WebSocket stream
    auto ws = std::make_shared<beast::websocket::stream<tcp::socket>>(std::move(socket));

    // Accept the WebSocket handshake
    ws->async_accept(
        [ws](beast::error_code ec) {
            if (ec) {
                std::cerr << "Handshake error: " << ec.message() << std::endl;
                return;
            }

            // Function to handle reading messages in a loop
            auto buffer = std::make_shared<beast::flat_buffer>();
            auto readMessage = std::make_shared<std::function<void()>>(); // Shared to allow recursion

            *readMessage = [ws, buffer, readMessage]() mutable {
                ws->async_read(
                    *buffer,
                    [ws, buffer, readMessage](beast::error_code ec, std::size_t bytes_transferred) mutable {
                        if (ec) {
                            if (ec == beast::websocket::error::closed) {
                                std::cout << "Connection closed by client." << std::endl;
                            } else {
                                std::cerr << "Read error: " << ec.message() << std::endl;
                            }
                            return;
                        }

                        // Log the received message
                        std::string message = beast::buffers_to_string(buffer->data());
                        std::cout << "Received: " << message << std::endl;

                        // Echo the message back
                        ws->text(true);
                        ws->async_write(
                            asio::buffer(message),
                            [ws, buffer, readMessage](beast::error_code ec, std::size_t bytes_transferred) mutable {
                                if (ec) {
                                    std::cerr << "Write error: " << ec.message() << std::endl;
                                    return;
                                }

                                // Clear the buffer and continue reading
                                buffer->consume(buffer->size());
                                (*readMessage)(); // Continue the loop
                            });
                    });
            };

            // Start the read loop
            (*readMessage)();
        });
}


