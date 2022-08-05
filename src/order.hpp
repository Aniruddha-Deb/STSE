#pragma once

#include "agent.hpp"

struct Order {
    uint64_t order_id;
    uint64_t timestamp;
    double price;
    uint32_t volume;
    Agent& owner;
};
