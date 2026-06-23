#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Utils
{
	public:
		static void allBig(string &input)
		{
			for(size_t i = 0; i < input.size(); i++)
				{
					input.at(i) = std::toupper(input.at(i));
				}
		}

		static void allSmall(string &input)
		{
			for(size_t i = 0; i < input.size(); i++)
			{
				input.at(i) = std::tolower(input.at(i));
			}
		}
};

#endif // UTILS_HPP
