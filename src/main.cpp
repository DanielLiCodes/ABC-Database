#include "HTTPServer.cpp"
#include "./Nodes/JSONNode.cpp"
#include "DatabaseManager.cpp"

using namespace httplib;

int main() {
    DatabaseManager* manager = new DatabaseManager();
    Server* svr = setupRoutes(manager);
    svr->listen("0.0.0.0", 8080);
}       