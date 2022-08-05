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

    void place_buy_order(double price, uint32_t volume, Agent& buyer);
    void place_sell_order(double price, uint32_t volume, Agent& seller);
    void place_buy_sell_order(double buy, double sell, uint32_t buy_vol, uint32_t sell_vol, Agent& owner);
    void fill_buy_order(uint64_t order_id, Agent& seller);
    void fill_sell_order(uint64_t order_id, Agent& buyer);
    void fill_buy_order(uint64_t order_id, uint64_t volume, Agent& seller);
    void fill_sell_order(uint64_t order_id, uint64_t volume, Agent& buyer);
    Order& get_best_buy_order();
    Order& get_best_sell_order();

};