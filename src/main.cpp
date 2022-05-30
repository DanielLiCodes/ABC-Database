#include "HTTPServer.cpp"
#include <iostream>
using namespace httplib;
using namespace std;


int main() {
    DatabaseManager manager;
    Server svr;
    setupRoutes(manager, svr);
    svr.listen("0.0.0.0", 8080);
    return 0;
}       