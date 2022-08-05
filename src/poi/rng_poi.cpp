#include <iostream>
#include <random>
#include <unordered_map>
#include <queue>

class NormalRNG {
 
    std::mt19937 mte;
    std::normal_distribution<> dist;

public:
    NormalRNG(double mu, double sigma);
    double gen_rand();
};

NormalRNG::NormalRNG(double mu, double sigma): mte{std::random_device()()}, dist{mu,sigma} {} 

double NormalRNG::gen_rand() {
    return dist(mte); 
}

class Actor {

public:
    Actor();

    //void set_market(Market& market);
    void notify_market_open();
    void notify_market_close();
    void notify_order_fill(uint64_t order_id, uint32_t volume);
};

struct Order {
    uint64_t order_id;
    uint64_t timestamp;
    double price;
    uint32_t volume;
    Actor& owner;
};

enum OrderSort {
    BUY, SELL
};

template<OrderSort oe>
class OrderCompare {

public:
    static const bool comp(const Order& a, const Order& b) {
        if (oe == OrderSort::BUY) return a.price < b.price;
        else return a.price > b.price;
    }

    static const bool equiv(const Order& a, const Order& b) {
        return a.order_id == b.order_id;
    }
};

class OrderBook {
    std::priority_queue<Order, std::vector<Order>, OrderCompare<OrderSort::BUY>> buy_book;
    std::priority_queue<Order, std::vector<Order>, OrderCompare<OrderSort::SELL>> sell_book;

public:

    void place_buy_order(double price, uint32_t volume, Actor& owner);
    void place_sell_order(double price, uint32_t volume, Actor& owner);
    void place_buy_sell_order(double buy, double sell, uint32_t buy_vol, uint32_t sell_vol, Actor& owner);
};


class Market {

    std::unordered_map<std::string,OrderBook> orders;
    std::vector<Actor> participants;

    uint64_t curr_order_id = 0;

public:
    Market();
    
    void market_open();
    void market_close();
};



int main() {

    int X = 5;
    long long i{X};

    Actor a();
    

    return 0;
}