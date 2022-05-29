#include "HTTPServer.cpp"
#include <iostream>
using namespace httplib;
using namespace std;


int main() {
    vector<Database*>* databases = new vector<Database*>();
    databases->push_back(new ArrayDatabase("array"));
    DatabaseManager* manager = new DatabaseManager(databases);
    cout << &manager << endl;
    Server* svr = setupRoutes(manager);
    svr->listen("0.0.0.0", 8080);
}       