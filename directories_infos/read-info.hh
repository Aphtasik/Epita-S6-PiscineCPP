#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

#include "directory-info.hh"

DirectoryInfo* read_info(std::ifstream& file);
