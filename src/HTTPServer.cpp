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
        cout << "[create] 2" << endl;
        auto val = req.get_param_value("name");
        auto type = req.get_param_value("type");
        if(val != "" && type != "") {
            manager->createDatabase(val, type);
            res.set_content("Database created", "text/plain");
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
        }
        return;
        });

    // GET /databases/list
    svr->Get("/databases/list", [manager](const Request &req, Response &res)
             {
        cout << "[list]" << endl;
        stringstream ss;

        if(manager->getDatabases().size() == 0) {
            ss << "No databases found";
        }
        else {
            for(auto db : manager->getDatabases()) {
                ss << db->getName() << " ";
            }
        }
        res.set_content(ss.str(), "text/plain");
        return;
         });

    svr->Get("/stop", [&](const Request &req, Response &res)
             {
        cout << "[stop]" << endl;
        res.set_content("Server stopped", "text/plain");
        svr->stop(); });

    return svr;
}

