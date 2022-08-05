#include "order_book.hpp"

template<OrderSort oe>
const bool OrderCompare<oe>::comp(const Order& a, const Order& b){
    if (oe == OrderSort::BUY) return a.price < b.price;
    else return a.price > b.price;
}

template<OrderSort oe>
const bool OrderCompare<oe>::equiv(const Order& a, const Order& b) {
    return a.order_id == b.order_id;
}

void OrderBook::place_buy_order(double price, uint32_t volume, Agent& buyer) {
    // implement in a thread-safe manner
}

void OrderBook::place_sell_order(double price, uint32_t volume, Agent& seller) {
    // implement in a thread-safe manner
}

void OrderBook::place_buy_sell_order(double buy, double sell, uint32_t buy_vol, uint32_t sell_vol, Agent& owner) {
    // implement in a thread-safe manner
}

void OrderBook::fill_buy_order(uint64_t order_id, Agent& seller) {
    // implement in a thread-safe manner
}

void OrderBook::fill_sell_order(uint64_t order_id, Agent& buyer) {
    // implement in a thread-safe manner
}

void OrderBook::fill_buy_order(uint64_t order_id, uint64_t volume, Agent& seller) {
    // implement in a thread-safe manner
}

void OrderBook::fill_sell_order(uint64_t order_id, uint64_t volume, Agent& buyer) {
    // implement in a thread-safe manner
}

// Order& OrderBook::get_best_buy_order() {
//     // implement in a thread-safe manner
// }

// Order& OrderBook::get_best_sell_order() {
//     // implement in a thread-safe manner
// }

