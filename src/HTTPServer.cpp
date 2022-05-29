#include "http/httplib.h"
#include "DatabaseManager.cpp"
using namespace httplib;
using namespace std;
#include <iostream>
void printRoute(const string &route) {
    cout << "Route: " << route << endl;
}


Server *setupRoutes(DatabaseManager *manager)
{
    Server *svr = new Server();
    svr->new_task_queue = [] { return new ThreadPool(1); };

    // GET /create [:)]
    svr->Get("/database/create", [manager](const Request &req, Response &res) {
        printRoute("/database/create");

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

    // GET /databases/list [:)]
    svr->Get("/database/list", [manager](const Request &req, Response &res) {
        printRoute("/database/list");
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

    // GET /database/get [:)]
    svr->Get("/database/get", [manager](const Request &req, Response &res) {
        printRoute("/database/get");

        auto dbName = req.get_param_value("db");
        auto key = req.get_param_value("key");

        if(dbName != "" && key != "") {
            Database* db = manager->getDatabase(dbName);
            if(db != nullptr) {
                DatabaseNode* node = db->get(key);
                if(node != nullptr) {
                    res.set_content(node->print(), "text/plain");
                    return;
                }
                else {
                    res.status = 404;
                    res.set_content("Key not found", "text/plain");
                    return;
                }
                delete node;
            }
            else {
                res.status = 404;
                res.set_content("Database not found", "text/plain");
                return;
            }
            delete db;
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
            return;
        }
    });


    
    // GET /database/add [:)]
    svr->Get("/database/add", [manager](const Request &req, Response &res) {
        printRoute("/database/add");

        auto dbName = req.get_param_value("db");
        auto context = req.get_param_value("context");

        if(dbName != "" && context != "") {
            Database* db = manager->getDatabase(dbName);
            if(db != nullptr) {
                db->add(context);
                res.set_content("Added", "text/plain");
                return;
            }
            else {
                res.status = 404;
                res.set_content("Database not found", "text/plain");
                return;
            }
            delete db;
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
            return;
        }
    });

    // GET /database/set [:)]
    svr->Get("/database/set", [manager](const Request &req, Response &res) {
        printRoute("/database/set");

        auto dbName = req.get_param_value("db");
        auto key = req.get_param_value("key");
        auto context = req.get_param_value("context");

        if(dbName != "" && key != "" && context != "") {
            Database* db = manager->getDatabase(dbName);
            if(db != nullptr) {
                DatabaseNode* node = db->get(key);
                if(node != nullptr) {
                    node->set(context);
                    res.set_content("Modified content", "text/plain");
                    return;
                }
                else {
                    res.status = 404;
                    res.set_content("Key not found", "text/plain");
                    return;
                }
                delete node;
            }
            else {
                res.status = 404;
                res.set_content("Database not found", "text/plain");
                return;
            }
            delete db;
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
            return;
        }
    });

    // GET /database/remove [:)]
    svr->Get("/database/remove", [manager](const Request &req, Response &res) {
        printRoute("/database/remove");

        auto dbName = req.get_param_value("db");
        auto key = req.get_param_value("key");

        if(dbName != "" && key != "") {
            Database* db = manager->getDatabase(dbName);
            if(db != nullptr) {
                db->remove(key);
            }
            else {
                res.status = 404;
                res.set_content("Database not found", "text/plain");
            }
            delete db;
        }
        else {
            res.status = 400;
            res.set_content("Invalid request", "text/plain");
        }
        return;
    });

    // GET /stop [:)]
    svr->Get("/stop", [&](const Request &req, Response &res) {
        printRoute("/stop");
        res.set_content("Server stopped", "text/plain");
        svr->stop();
        return;
    });

    return svr;
}
