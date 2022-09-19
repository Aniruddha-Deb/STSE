#include <asio.hpp>
#include <string>
#include <unordered_map>
#include <atomic>

#include "orderbook.hpp"

class Server {

    std::atomic<std::unordered_map<std::string,OrderBook>> books;

public:

    void run(int n_threads) {

    }
};