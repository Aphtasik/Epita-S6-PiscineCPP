#include <fstream>
#include <iostream>

void stdin_to_file()
{
    std::ofstream file_out("file.out");
    std::string line;

    while (std::cin >> line) // input from the file in.txt
    {
        file_out << line << "\n"; // output to the file out.txt
    }

    file_out.close();
}
