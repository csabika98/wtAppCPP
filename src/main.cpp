#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WTemplate.h>
#include <Wt/WServer.h>
#include <filesystem>
#include <functional>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <iostream>

class HelloApplication : public Wt::WApplication {
public:
    explicit HelloApplication(const Wt::WEnvironment& env, std::string resourcePath)
        : Wt::WApplication(env), resourcePath_(std::move(resourcePath))
    {
        setTitle("Hello Wt");



        // Read the HTML template from the file
        std::string templateContent;
        try {
            templateContent = readFile(resourcePath_ + "/index.html");
        } catch (const std::exception& e) {
            std::cerr << "Error reading template: " << e.what() << std::endl;
        }

        // Create a WTemplate instance and set the template text
        auto templateWidget = root()->addWidget(std::make_unique<Wt::WTemplate>());
        templateWidget->setTemplateText(templateContent, Wt::TextFormat::UnsafeXHTML);

        // Bind variables to the template
        templateWidget->bindString("username", "User");

    }

private:
    std::string resourcePath_;

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

int main(int argc, char** argv) {
    try {
        // Get the current executable path
        std::filesystem::path execPath = std::filesystem::current_path();

        // Navigate up two levels to get to the project root and resolve the canonical path
        std::filesystem::path projectRoot = std::filesystem::canonical(execPath / ".." / "..");

        // Construct the path to the resources directory and resolve the canonical path
        std::filesystem::path resourcesDir = std::filesystem::canonical(projectRoot / "docroot");

        // Convert to string and use as docroot
        std::string docroot = resourcesDir.string();

        // Debug output for paths
        std::cout << "Executable Path: " << execPath << std::endl;
        std::cout << "Project Root: " << projectRoot << std::endl;
        std::cout << "Resources Directory: " << resourcesDir << std::endl;
        std::cout << "Docroot: " << docroot << std::endl;

        // Add the constructed docroot to the arguments
        std::vector<std::string> args(argv, argv + argc);
        args.emplace_back("--docroot");
        args.push_back(docroot);

        // Adding http-address and port for completeness
        args.emplace_back("--http-address");
        args.emplace_back("0.0.0.0");
        args.emplace_back("--http-port");
        args.emplace_back("8080");

        std::vector<const char*> c_args;
        c_args.reserve(args.size());
        for (const auto& arg : args) {
            c_args.push_back(arg.c_str());
        }

        // Initialize Wt server with the modified arguments
        Wt::WServer server(static_cast<int>(c_args.size()), const_cast<char**>(c_args.data()), WTHTTP_CONFIGURATION);

        // Set up the configuration
        server.setServerConfiguration(static_cast<int>(c_args.size()), const_cast<char**>(c_args.data()), WTHTTP_CONFIGURATION);

        // Register the entry point with the resource path
        server.addEntryPoint(Wt::EntryPointType::Application, [docroot](const Wt::WEnvironment& env) {
            return createApplication(env, docroot);
        });

        // Start the server
        if (server.start()) {
            int sig = Wt::WServer::waitForShutdown();
            server.stop();
            return sig;
        } else {
            return 1;
        }
    }
    catch (Wt::WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
        return 1;
    }
}


