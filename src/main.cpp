#include <asio.hpp>
#include <lyra/lyra.hpp>
#include <iostream>
#include <csignal>

using asio::ip::tcp;

static volatile sig_atomic_t killed = 0;

void handle_terminate(int signum) {
    killed = 1;
}

struct ConnectionRequest {
    char username[16];
    char password[16];
};

void accept_handler(const asio::error_code& error, tcp::socket peer) {
    if (!error) {
        // success
        std::cout << "Accepted async socket" << std::endl;
    }
}

int main(int argc, char** argv) {

    std::signal(SIGHUP, handle_terminate);
    std::signal(SIGINT, handle_terminate);

    int port = 5000;
    bool show_help;

    auto cli = lyra::help(show_help)
        | lyra::opt(port, "connection request port")
            ["-p"]["--port"]
            ("port to run connection socket on");

    auto result = cli.parse({argc, argv});
    if (!result) {
        std::cerr << "Error in command line: " << result.message() << std::endl;
        exit(1);
    }
    if (show_help) {
        std::cout << cli << std::endl;
        return 0;
    }

    // wait for connection on port 5000
    asio::io_context io_context;

    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    tcp::socket socket;

    while(!killed) {
        acceptor.async_accept(socket, accept_handler);


    }

    // TODO terminate all other threads as well
    std::cout << "Cleanly terminated" << std::endl;

    return 0;
}