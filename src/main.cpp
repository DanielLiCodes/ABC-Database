#include "HTTPServer.cpp"
using namespace Pistache;


int main() {
    Rest::Router all = routes_definer();

    
    Address addr(Ipv4::any(), Port(9080));
    auto opts = Http::Endpoint::options()
                    .threads(1);

    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(all.handler());
    server.serve();
}