#include "word-count.hh"

#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    ssize_t count = 0;
    std::string i;
    std::ifstream file_in;
    std::string line;

    file_in.open(filename);
    if (!file_in.is_open())
        return -1;

    while (file_in >> i)
        count++;

    return count;
}
