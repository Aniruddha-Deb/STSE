#include <cinttypes>
#include <string>
#include <queue>

class OrderBook {

    // TODO init DS's, deal with timestamping orders etc.

public:

    OrderBook(uint32_t tickerid, std::string ticker);

    void add_buy_order(uint32_t id,  float price, uint32_t volume);

    void add_sell_order(uint32_t id, float price, uint32_t volume);
};