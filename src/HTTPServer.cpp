#include "pistache/endpoint.h"
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;
using namespace Rest;

void HelloWord(const Rest::Request& request, Http::ResponseWriter response) {
     response.send(Http::Code::Ok, "Hello, World\n");
}

Rest::Router routes_definer() {
    Rest::Router router;
    Routes::Get(router, "/users/all", Routes::bind(&HelloWord));
    return router;
}

