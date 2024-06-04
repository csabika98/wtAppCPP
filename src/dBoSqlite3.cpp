#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Sqlite3.h>
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

//int main() {
//    // Set up the connection to the database
//    auto sqlite3 = std::make_unique<dbo::backend::Sqlite3>("database.db");
//    sqlite3->setProperty("show-queries", "true");
//    sqlite3->setDateTimeStorage(dbo::SqlDateTimeType::Date, dbo::backend::DateTimeStorage::ISO8601AsText);
//    sqlite3->setDateTimeStorage(dbo::SqlDateTimeType::DateTime, dbo::backend::DateTimeStorage::ISO8601AsText);
//
//    dbo::Session session;
//    session.setConnection(std::move(sqlite3));
//    session.mapClass<A>("a");
//
//    // Create tables if they do not exist
//    session.createTables();
//
//    // Insert a new record
//    {
//        std::string date = "1950-03-12";
//        std::string dateTime = "1969-12-31T23:59:59.999";
//        std::string timePoint = "1990-02-14T01:50:05.012";
//
//        dbo::Transaction t(session);
//        auto a = session.addNew<A>();
//        a.modify()->date = date;
//        a.modify()->dateTime = dateTime;
//        a.modify()->timePoint = timePoint;
//    }
//
//    // Perform a query to retrieve the record
//    {
//        dbo::Transaction t(session);
//        auto result = session.query<std::tuple<std::string, std::string, std::string>>(
//                "SELECT date, date_time, time_point FROM a"
//        ).limit(1).resultValue();
//
//        std::string dateStr, dateTimeStr, timePointStr;
//        std::tie(dateStr, dateTimeStr, timePointStr) = result;
//
//        std::cout << "Date: " << dateStr << std::endl;
//        std::cout << "DateTime: " << dateTimeStr << std::endl;
//        std::cout << "TimePoint: " << timePointStr << std::endl;
//    }
//
//    return 0;
//}


