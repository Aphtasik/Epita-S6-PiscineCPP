#include "read-info.hh"

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file)
{
    if (!file.is_open() || file.eof())
        return nullptr;

    std::string line;
    std::string name;
    std::string owner;
    unsigned int size;
    unsigned int rights;

    std::getline(file, line);
    std::stringstream ss(line);

    if (!(ss >> name >> std::dec >> size >> std::oct >> rights >> owner))
        return nullptr;
    if (!ss.eof())
        return nullptr;
    return new DirectoryInfo(name, size, rights, owner);
}
