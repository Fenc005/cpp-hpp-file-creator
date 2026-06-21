#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class utils
{
   public:
      static void allBig(string &input)
      {
         for(int i = 0; i < input.size(); i++)
            {
               input.at(i) = std::toupper(input.at(i));
            }
      }

      static void allSmall(string &input)
      {
         for(int i = 0; i < input.size(); i++)
         {
            input.at(i) = std::tolower(input.at(i));
         }
      }
};
