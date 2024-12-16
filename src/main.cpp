#include "websocket_server.h"
#include <boost/asio.hpp>
#include <iostream>

int main() {
    try {
        // Set up the I/O context
        asio::io_context ioc;

        // Create the WebSocket server
        tcp::endpoint endpoint(asio::ip::make_address("0.0.0.0"), 9000);
        WebSocketServer server(ioc, endpoint);

        // Run the server
        std::cout << "WebSocket Server is running on ws://0.0.0.0:9000" << std::endl;
        server.run();

        // Block until the server stops
        ioc.run();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
