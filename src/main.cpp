#include <lyra/lyra.hpp>
#include <iostream>

int main(int argc, char** argv) {

    int num_bots, num_stocks;
    bool show_help;

    auto cli = lyra::help(show_help)
        | lyra::opt(num_bots, "number of bots")
            ["-b"]["--bots"]
            ("number of machine bots to run")
        | lyra::opt(num_stocks, "number of stocks" )
            ["-s"]["--stocks"]
            ("number of stocks to create");

    auto result = cli.parse({argc, argv});
    if (!result) {
        std::cerr << "Error in command line: " << result.message() << std::endl;
        exit(1);
    }
    if (show_help) {
        std::cout << cli << std::endl;
        return 0;
    }

    std::cout << "num_bots = " << num_bots << std::endl;
    std::cout << "num_stocks = " << num_stocks << std::endl;

    return 0;
}