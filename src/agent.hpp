#pragma once

class Agent {

public:
    Agent();

    void notify_market_open();
    void notify_market_close();
    void notify_order_fill(uint64_t order_id, uint32_t volume);
    void notify_order_close(uint64_t order_id);
};