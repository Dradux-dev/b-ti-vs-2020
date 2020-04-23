#include <iostream>

#include <experimental/net>


int main(int, char**) {
    using namespace std::experimental;

    net::io_context io_context;
    net::ip::tcp::resolver resolver(io_context);
    std::cout << net::ip::host_name() << std::endl;
    auto result = resolver.resolve(net::ip::host_name(), "http");
    for (net::ip::tcp::endpoint ep : result) {
        std::cout << ep.address().to_string() << std::endl;
    }

    return 0;
}
