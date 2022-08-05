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