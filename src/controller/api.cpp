#include "api.h"
#include <iostream>
// All the logic is implemented in the header file for simplicity.
// You could move the implementation here if desired, but it's not necessary for this example.


void setupApiEndpoints(Wt::WServer& server) {
    auto apiResource = std::make_shared<DynamicApiResource>();

    // Add dynamic endpoints
    apiResource->addEndpoint("/testendpoint", [](const Wt::Http::Request&, Wt::Http::Response& response) {
        response.out() << R"({"message": "Csaba"})";
    });

    apiResource->addEndpoint("/anotherendpoint", [](const Wt::Http::Request&, Wt::Http::Response& response) {
        response.out() << R"({"message": "Another endpoint response"})";
    });

    // Register the resource with the specific paths
    server.addResource(apiResource, "/api/testendpoint");
    server.addResource(apiResource, "/api/anotherendpoint");

    std::cout << "API endpoints registered." << std::endl;
}