#include <cassert>
#include <string>

#include "singleton.hh"

int main()
{
    Logger::instance()->open_log_file("logs.log");
    Logger::instance()->write_to_log_file();
    Logger::instance()->close_log_file();
    auto l = Logger::instance();
    l->close_log_file();

    return 0;
}
