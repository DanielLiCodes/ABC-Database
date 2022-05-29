#include "http/httplib.h"
#include "DatabaseManager.cpp"
using namespace httplib;
using namespace std;
#include <iostream>
Server *setupRoutes(DatabaseManager *manager)
{
    Server *svr = new Server();

    // GET /create
    svr->Get("/create", [manager](const Request &req, Response &res)
             {
        cout << "[create]" << endl;
        auto val = req.get_param_value("name");
        auto type = req.get_param_value("type");
        if(val != "" && type != "") {
            res.set_content("Database created", "text/plain");
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
        }
        res.set_content(val, "text/plain"); });

    // GET /databases/list
    svr->Get("/databases/list", [manager](const Request &req, Response &res)
             {
        cout << "[list]" << endl;

        if(manager->getDatabases()->size() == 0) {
            res.set_content("No databases found", "text/plain");
        }
        else {
            res.set_content(manager->printDatabases(), "text/plain");
        } });

    svr->Get("/stop", [&](const Request &req, Response &res)
             {
        cout << "[stop]" << endl;
        res.set_content("Server stopped", "text/plain");
        svr->stop(); });

    return svr;
}
