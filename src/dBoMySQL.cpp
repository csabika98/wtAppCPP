#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/MySQL.h>
#include <iostream>
#include <chrono>

namespace dbo = Wt::Dbo;

class A : public dbo::Dbo<A> {
public:
    std::string date;
    std::string dateTime;
    std::string timePoint;

    template<typename Action>
    void persist(Action& a)
    {
        dbo::field(a, date, "date");
        dbo::field(a, dateTime, "date_time");
        dbo::field(a, timePoint, "time_point");
    }
};

int main() {
    // Set up the connection to the database
    auto mysql = std::make_unique<dbo::backend::MySQL>("wtapp", "root", "Derank259", "127.0.0.1");
    dbo::Session session;
    session.setConnection(std::move(mysql));
    session.mapClass<A>("a");

    // Create tables if they do not exist
    session.createTables();

    // Insert a new record
    {
        std::string date = "1950-03-12";
        std::string dateTime = "1969-12-31T23:59:59.999";
        std::string timePoint = "1990-02-14T01:50:05.012";

        dbo::Transaction t(session);
        auto a = session.addNew<A>();
        a.modify()->date = date;
        a.modify()->dateTime = dateTime;
        a.modify()->timePoint = timePoint;
    }

    // Perform a query to retrieve the record
    {
        dbo::Transaction t(session);
        auto result = session.query<std::tuple<std::string, std::string, std::string>>(
                "SELECT date, date_time, time_point FROM a"
        ).limit(1).resultValue();

        std::string dateStr, dateTimeStr, timePointStr;
        std::tie(dateStr, dateTimeStr, timePointStr) = result;

        std::cout << "Date: " << dateStr << std::endl;
        std::cout << "DateTime: " << dateTimeStr << std::endl;
        std::cout << "TimePoint: " << timePointStr << std::endl;
    }

    return 0;
}

