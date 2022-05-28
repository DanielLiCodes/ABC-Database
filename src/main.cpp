#include "HTTPServer.cpp"
#include "DatabaseManager.cpp"
using namespace Pistache;
int main() {
    Document d;
    Rest::Router router = setupRoutes();
    Address addr(Ipv4::any(), Port(9080));
    auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);


    
    server.init(opts);
    server.setHandler(router.handler());
    server.serve();
}