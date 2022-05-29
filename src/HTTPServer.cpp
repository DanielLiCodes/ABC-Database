#include "http/httplib.h"
#include "DatabaseManager.cpp"
using namespace httplib;

Server *setupRoutes(DatabaseManager *manager)
{
    Server *svr = new Server();

    // GET /create
    svr->Get("/create", [&](const Request &req, Response &res) {
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
        res.set_content(val, "text/plain"); 
    });

    // GET /databases/list
    svr->Get("/databases/list", [&](const Request &req, Response &res) {
        stringstream ss;
        for(unsigned int i = 0; i < manager->size(); i++) {
            ss << manager->getDatabases()[i]->getName() << endl;
        }
        res.set_content(ss.str(), "text/plain"); 
    });

    
    return svr;
}
