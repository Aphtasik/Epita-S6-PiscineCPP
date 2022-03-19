#include "read-info.hh"

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file)
{
    if (file.eof())
        return nullptr;
    if (!file.is_open())
        return nullptr;

    std::string line, name, owner;
    unsigned int size, rights;

    std::getline(file, line);
    std::stringstream ss;
    ss.str(line);

    if(!(ss >> name >> std::dec >> size >> std::oct >> rights >> owner));
        return nullptr;
    if (file.peek() == '\n' || !file.eof())
        return nullptr;

    DirectoryInfo d = DirectoryInfo(name, size, rights, owner);
    return &d;
}
