#ifndef ROUTES_H
#define ROUTES_H

#include <Wt/WApplication.h>
#include <memory>
#include <string>

std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env, const std::string& resourcePath);

#endif // ROUTES_H
