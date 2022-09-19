#include <cinttypes>

const uint8_t CMD_LOGIN    = 0x01;
const uint8_t CMD_LOGINOK  = 0x02;
const uint8_t CMD_BUY      = 0x03;
const uint8_t CMD_BUYOK    = 0x04;
const uint8_t CMD_SELL     = 0x05;
const uint8_t CMD_SELLOK   = 0x06;
const uint8_t CMD_TICKER   = 0x07; // list the ticker ID's
const uint8_t CMD_TICKEROK = 0x08;
const uint8_t CMD_BOOK     = 0x09; // gets the order book for a particular ticker
const uint8_t CMD_BOOKOK   = 0x0A;
const uint8_t CMD_CLIENT   = 0x0B; // gets information about other traders' client-uid mapping
const uint8_t CMD_CLIENTOK = 0x0C;

const uint8_t ORDER_BUY    = 0x01;
const uint8_t ORDER_SELL   = 0x02;

struct LoginData {
    char uname[8];
    char pass[8];
};

struct LoginOkData {
    uint32_t uid;
};

struct OrderData {
    uint32_t uid; // send UID along with every order? yeah
    uint32_t tickerid;
    float    price;
    uint32_t volume;
};

struct OrderOkData {
    uint32_t uid;
};

struct TickerData {
    uint32_t uid;
};

struct TickerOkData {
    uint32_t n_tickers;
};

struct BookData {
    uint32_t uid;
    uint32_t tickerid;
};

struct BookOkData {
    uint32_t n_orders;
};

struct ClientData {
    uint32_t uid;
};

struct ClientOkData {
    uint32_t n_clients;
};

union ControlData {
    LoginData login;
    LoginOkData loginok;
    OrderData order;
    OrderOkData orderok;
    TickerData ticker;
    TickerOkData tickerok;
    BookData book;
    BookOkData bookok;
    ClientData client;
    ClientOkData clientok;
};

struct ControlPacket {
    uint8_t type;
    ControlData data;
};

struct TickerInfo {
    char ticker[8];
    uint32_t tickerid;
};

struct BookInfo {
    uint32_t uid;
    float    price;
    uint32_t volume;
    uint8_t  ordertype;
};

struct ClientInfo {
    char uname[8];
    uint32_t uid;
};

struct Tick {
    uint8_t  ordertype;
    uint32_t tickerid;
    uint32_t uid;
    float    price;
    uint32_t volume;
};