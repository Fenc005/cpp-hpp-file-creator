#ifndef MESSAGES_HPP
#define MESSAGES_HPP

#include <iostream>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Messages
{
	private:
		inline static const unordered_map<string, string> ERROR_MESSAGES =
		{
			{"INVALID_FILENAME", "[ERROR] Invalid filename entered"},
			{"INVALID_COMMAND", "[ERROR] Invalid command entered"},
		};

		inline static const unordered_map<string, string> NORMAL_MESSAGES =
		{
			{"WELCOME_LINE", "------------------------------------"},
			{"WELCOME_MSSG", "Welcome to the cpp/hpp file creator!"},
			{"INPUT_MSSG", "Please input the name of the file you want to create."},
			{"QUIT_INFO", "(Use QUIT to end the program)"},
			{"INPUT_WAIT", " > "},
		};

		inline static const unordered_map<string, string> FILE_CONTENTS =
		{
			{"IFNDEF", "#ifndef"},
			{"DEFINE", "#define"},
			{"ENDIF", "#endif"},
			{"HPP", "_HPP"},
			{"INCLUDE", "#include"},
			{"CLASS", "class"},
			{"BRACKETS", "{\n\n};"},
			{"PRIVATE", "private:"},
			{"PUBLIC", "public:"},
		};

	public:
		static string getErrorMessages(const string key)
		{
			return ERROR_MESSAGES.at(key);
		}

		static string getNormalMessage(const string key)
		{
			return NORMAL_MESSAGES.at(key);
		}

		static string getFileContents(const string key)
		{
			return FILE_CONTENTS.at(key);
		}
};

#endif //MESSAGES_HPP