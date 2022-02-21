#include <fstream>
#include <iostream>

void stdin_to_file()
{
    std::string line;
    while (std::getline(std::cin, line)) // input from the file in.txt
    {
        std::cout << line << "\n"; // output to the file out.txt
    }
}
