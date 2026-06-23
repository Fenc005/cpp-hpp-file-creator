#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <format>
#include <unordered_map>
#include <vector>
#include <filesystem>
#include <optional>

#include "classes/messages.hpp"
#include "classes/utils.hpp"

using std::string;
using std::vector;

using std::cout;
using std::endl;
using std::cin;
using std::flush;

using std::format;
using std::unordered_map;
using std::optional;
using std::nullopt;

using std::ostream;
using std::ifstream;
using std::fstream;
using std::ofstream;

using std::filesystem::path;
using std::filesystem::exists;
using std::filesystem::create_directory;
using std::filesystem::create_directories;
using std::filesystem::current_path;
using std::filesystem::file_size;

#endif // BASE_HPP