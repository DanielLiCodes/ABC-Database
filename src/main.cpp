#include "../headers/DatabaseManager.h"
#include "HTTPServer.cpp"
using namespace Pistache;


int main() {
     Http::listenAndServe<HelloHandler>("*:9080");
}