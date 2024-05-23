#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>
#include <Wt/WAnchor.h>
#include <Wt/WLink.h>
#include <Wt/WText.h>
#include <filesystem>
#include <memory>
#include <string>
#include <unordered_map>

#include <fstream>
#include <sstream>
#include <utility>


class HelloApplication : public Wt::WApplication {
public:
    explicit HelloApplication(const Wt::WEnvironment& env, std::string  resourcePath)
        : Wt::WApplication(env), resourcePath_(std::move(resourcePath))
    {
        setTitle("Hello Wt");

        // Navigation links
        auto linkContainer = root()->addWidget(std::make_unique<Wt::WContainerWidget>());
        linkContainer->addWidget(std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath, "/"), "Home"));
        linkContainer->addWidget(std::make_unique<Wt::WText>(" | "));
        linkContainer->addWidget(std::make_unique<Wt::WAnchor>(Wt::WLink(Wt::LinkType::InternalPath, "/newroute"), "Go to New Route"));

        // Initialize routes
        initRoutes();

        // Handle internal path changes
        internalPathChanged().connect(this, &HelloApplication::handleInternalPath);

        // Handle the initial internal path
        handleInternalPath(internalPath());
    }

private:
    std::string resourcePath_;
    std::unordered_map<std::string, std::string> routeMap_;

    void initRoutes() {
        addRoute("/", "index.html");
        addRoute("/newroute", "new_route.html");
    }

    void addRoute(const std::string& path, const std::string& templateFile) {
        routeMap_[path] = resourcePath_ + "/" + templateFile;
    }

    void handleInternalPath(const std::string& path) {
        root()->clear();
        auto it = routeMap_.find(path);
        if (it != routeMap_.end()) {
            std::string templateContent = readFile(it->second);
            auto templateWidget = root()->addWidget(std::make_unique<Wt::WTemplate>());
            templateWidget->setTemplateText(templateContent, Wt::TextFormat::UnsafeXHTML);
            templateWidget->bindString("username", "User");
        } else {
            root()->addWidget(std::make_unique<Wt::WText>("404 - Page not found"));
        }
    }

    static std::string readFile(const std::string& filePath) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file: " + filePath);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env, const std::string& resourcePath) {
    return std::make_unique<HelloApplication>(env, resourcePath);
}



