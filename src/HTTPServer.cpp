#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;
using namespace Rest;

void HelloWorld(const Rest::Request& request, Http::ResponseWriter response) {
     response.send(Http::Code::Ok, "Hello, World\n");
}

Rest::Router setupRoutes() {
    Rest::Router router;
    Routes::Get(router, "/hw", Routes::bind(&HelloWorld));
    return router;
}

