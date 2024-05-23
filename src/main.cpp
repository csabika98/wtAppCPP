#include <Wt/WServer.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "controller/routes.h"

int main(int argc, char** argv) {
    try {
        std::filesystem::path execPath = std::filesystem::current_path();
        std::filesystem::path projectRoot = canonical(execPath / ".." / "..");
        std::filesystem::path resourcesDir = canonical(projectRoot / "docroot");
        std::string docroot = resourcesDir.string();

        std::vector<std::string> args(argv, argv + argc);
        args.emplace_back("--docroot");
        args.push_back(docroot + ";resources");

        args.emplace_back("--http-address");
        args.emplace_back("0.0.0.0");
        args.emplace_back("--http-port");
        args.emplace_back("8080");

        // Add deploy-path without ending slash
        args.emplace_back("--deploy-path");
        args.emplace_back("/");

        std::vector<const char*> c_args;
        c_args.reserve(args.size());
        for (const auto& arg : args) {
            c_args.push_back(arg.c_str());
        }

        Wt::WServer server(static_cast<int>(c_args.size()), const_cast<char**>(c_args.data()), WTHTTP_CONFIGURATION);
        server.setServerConfiguration(static_cast<int>(c_args.size()), const_cast<char**>(c_args.data()), WTHTTP_CONFIGURATION);
        server.addEntryPoint(Wt::EntryPointType::Application, [docroot](const Wt::WEnvironment& env) {
            return createApplication(env, docroot);
        });

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

