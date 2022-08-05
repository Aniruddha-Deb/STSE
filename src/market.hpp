#pragma once

#include <unordered_map>
#include <vector>

#include "order_book.hpp"

class Market {

    std::unordered_map<std::string,OrderBook> orders;
    std::vector<Agent> participants;

    uint64_t curr_order_id = 0;

public:
    Market();
    
    void market_open();
    void market_close();
};