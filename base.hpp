#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::unordered_map;

enum class Errors
{
  MEMORY,
  INVALID_PATH,
  UNEXPECTED,
};

class base
{
  public:
    const static unordered_map<Errors, string> messages = {
      {Errors::MEMORY, "[ERROR] Memory Allocation Failed"},
      {Errors::INVALID_PATH, "[ERROR] The path is invalid"},
      {Errors::UNEXPECTED, "[ERROR] An unexpected error just occured"},
    };
};

#endif //BASE_HPP