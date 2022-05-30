#include "HTTPServer.cpp"
#include <iostream>
using namespace httplib;
using namespace std;


int main() {
    DatabaseManager* manager = new DatabaseManager();
    cout << &manager << endl;
    Server* svr = setupRoutes(manager);
    svr->listen("0.0.0.0", 8080);
}       