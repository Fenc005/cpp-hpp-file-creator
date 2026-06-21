#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <format>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::format;

class Base
{
  public:
    inline static const string WELCOME_LINE = "------------------------------------";
    inline static const string WELCOME_MSSG = "Welcome to the cpp/hpp file creator!";

    inline static const string PROMPT = "Please input the name of the file you want to create.\n" 
    "(Use QUIT to end the program)";

    inline static const string INPUT_WAIT = " > ";

    inline static const string INVALID_STRING = "[ERROR] Invalid string given!";

    static bool checkSize(string &input)
    {
      if(input.size() <= 0)
      {
        cout << endl;
        cout << Base::INVALID_STRING << endl;
        cout << endl;
        return true;
      }

      return false;
    }

    static void FirstBigRestSmall(string &input)
    {
      for(int i = 0; i < input.size(); i++)
      {
        if(i == 0)
        {
          input.at(i) = std::toupper(input.at(i));
        }
        else
        {
          input.at(i) = std::tolower(input.at(i));
        }
      }
    }

    static void AllBig(string &input)
    {
      for(int i = 0; i < input.size(); i++)
      {
        input.at(i) = std::toupper(input.at(i));
      }
    }

    static void AllSmall(string &input)
    {
      for(int i = 0; i < input.size(); i++)
      {
        input.at(i) = std::tolower(input.at(i));
      }
    }
};

#endif // BASE_HPP