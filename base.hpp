#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <unordered_map>
#include <vector>
#include <filesystem>

#include "classes/messages.hpp"
#include "classes/utils.hpp"

using std::string;
using std::vector;

using std::cout;
using std::endl;
using std::cin;

using std::format;
using std::unordered_map;

using std::ostream;
using std::ifstream;
using std::fstream;

using std::filesystem::path;
using std::filesystem::exists;
using std::filesystem::create_directory;
using std::filesystem::create_directories;

const string DEFAULT_PATH = "creator";

#endif // BASE_HPP