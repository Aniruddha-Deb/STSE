#include <iostream>
#include <optional>
#include <asio.hpp>

class session : public std::enable_shared_from_this<session>
{
public:

    session(asio::ip::tcp::socket&& socket)
    : socket(std::move(socket))
    {
    }

    void start()
    {
        asio::async_read_until(socket, streambuf, "exit", [self = shared_from_this()] (asio::error_code error, std::size_t bytes_transferred)
        {
            // wow!
            std::cout << std::istream(&(self->streambuf)).rdbuf();
        });
    }

private:

    asio::ip::tcp::socket socket;
    asio::streambuf streambuf;
};

class server
{
public:

    server(asio::io_context& io_context, std::uint16_t port)
    : io_context(io_context)
    , acceptor  (io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
    , socket {io_context}
    {
    }

    void async_accept()
    {
        acceptor.async_accept(socket, [&] (asio::error_code error)
        {
            std::make_shared<session>(std::move(socket))->start();
            async_accept();
        });
    }

private:

    asio::io_context& io_context;
    asio::ip::tcp::acceptor acceptor;
    asio::ip::tcp::socket socket;
};

int main()
{
    asio::io_context io_context;
    server srv(io_context, 15001);
    srv.async_accept();
    io_context.run();
    return 0;
}