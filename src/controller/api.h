#ifndef API_H
#define API_H

#include <Wt/WResource.h>
#include <Wt/Http/Response.h>
#include <unordered_map>
#include <functional>
#include <Wt/WServer.h>

//class ApiResource : public Wt::WResource {
//public:
//    ApiResource() = default;

//    ~ApiResource() override = default;

//protected:
//    void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) override {
//        response.setMimeType("application/json");
//        response.addHeader("Access-Control-Allow-Origin", "*");
//        response.addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
//        response.addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
//
//        response.out() << R"({"message": "Csaba"})";
//    }
//};
class DynamicApiResource : public Wt::WResource {
public:
    using Handler = std::function<void(const Wt::Http::Request&, Wt::Http::Response&)>;

    DynamicApiResource() = default;
    ~DynamicApiResource() override = default;

    void addEndpoint(const std::string& path, Handler handler) {
        handlers_[path] = std::move(handler);
        std::cout << "Registered endpoint: " << path << std::endl;
    }

protected:
    void handleRequest(const Wt::Http::Request& request, Wt::Http::Response& response) override {
        response.setMimeType("application/json");
        response.addHeader("Access-Control-Allow-Origin", "*");
        response.addHeader("Access-Control-Allow-Methods", "GET, POST, PUT, DELETE, OPTIONS");
        response.addHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");

        std::string requestPath = request.path();
        std::cout << "Handling request for path: " << requestPath << std::endl;

        // Check if path starts with /api and strip it for matching
        if (requestPath.rfind("/api/", 0) == 0) { // Check if path starts with /api/
            std::string relativePath = requestPath.substr(4); // Remove /api
            auto it = handlers_.find(relativePath);
            if (it != handlers_.end()) {
                it->second(request, response);
                return;
            }
        }

        response.setStatus(404);
        response.out() << R"({"error": "Not found"})";
    }

private:
    std::unordered_map<std::string, Handler> handlers_;
};

// Function to set up and register API endpoints
void setupApiEndpoints(Wt::WServer& server);

#endif // API_H

