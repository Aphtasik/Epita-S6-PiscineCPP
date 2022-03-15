#include "singleton.hh"


void open_log_file(const std::string& file)
{
    std::cout << "LOG: Opening file " << file << '\n';
}

void write_to_log_file()
{

    std::cout << "LOG: Writing into log file ..." << '\n';
}

void close_log_file()
{
    std::cout << "LOG: Closing log file ..." << '\n';
}
