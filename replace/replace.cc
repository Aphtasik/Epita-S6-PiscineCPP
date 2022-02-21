#include "replace.hh"

#include <fstream>
#include <iostream>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    std::ofstream file_out;

    std::string strTmp;

    file_in.open(input_filename);
    if (!file_in)
    {
        std::cout << "Cannot open input file\n";
        return;
    }

    file_out.open(output_filename);
    if (!file_out)
    {
        std::cout << "Cannot write output file\n";
        return;
    }

    while (file_in >> strTmp)
    {
        if (strTmp == src_token)
        {
            file_out << dst_token << " ";
        }
        else
        {
            file_out << strTmp << " ";
        }
    }

    file_in.close();
    file_out.close();
}
