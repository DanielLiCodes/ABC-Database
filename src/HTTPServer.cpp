#include "pistache/description.h"
#include "pistache/endpoint.h"
#include "pistache/http.h"

using namespace Pistache;


Rest::Router routes_definer() {
    Rest::Router router;
    Routes::Get(router, "/users/all", Routes::bind(&HelloWord, this));
    return router;
}


void HelloWord(const Rest::Request& request, Http::ResponseWriter response) {
     response.send(Http::Code::Ok, "Hello, World\n");
}