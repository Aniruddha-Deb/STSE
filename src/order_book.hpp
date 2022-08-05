#pragma once

#include <queue>
#include <vector>

#include "order.hpp"
#include "agent.hpp"

enum OrderSort {
    BUY, SELL
};

template<OrderSort oe>
class OrderCompare {

public:
    static const bool comp(const Order& a, const Order& b);
    static const bool equiv(const Order& a, const Order& b);
};

class OrderBook {
    std::priority_queue<Order, std::vector<Order>, OrderCompare<OrderSort::BUY>> buy_book;
    std::priority_queue<Order, std::vector<Order>, OrderCompare<OrderSort::SELL>> sell_book;

public:

    void place_buy_order(double price, uint32_t volume, Agent& owner);
    void place_sell_order(double price, uint32_t volume, Agent& owner);
    void place_buy_sell_order(double buy, double sell, uint32_t buy_vol, uint32_t sell_vol, Agent& owner);
};