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
			{"INVALID_FILEPATH", "[ERROR] There was an error creating the parent directory"},
			{"INVALID_COMMAND", "[ERROR] Invalid command entered"},
			{"INVALID_LANGUAGE", "[SOFT ERROR] Invalid programing language entered, therefore defaulting to C"},
			{"INVALID_CLASS", "[SOFT ERROR] Answer was not valid, therefore defaulting to NO class"},
			{"NO_OPEN", "[ERROR] Failed to create files. Check folder permissions"},
		};

		inline static const unordered_map<string, string> NORMAL_MESSAGES =
		{
			{"WELCOME_LINE", "----------------------------------------"},
			{"WELCOME_MSSG", "--Welcome to the cpp/hpp file creator!--\n"
				"--------(also works for C files)--------"},
			{"INPUT_MSSG", "Please input the name of the file you want to create."},
			{"INPUT_WAIT", " > "},
			{"FILE_PATH", "Please input the file path you want your files to be saved at.\n"
			"(only the parent directory's path)"},
			{"C_OR_CPP", "Do you want to create files for C [C] or C++ [P]"},
			{"CLASS_OR_NO_CLASS", "Do you want to create the class? [YES]/[NO]"},

			{"QUIT_INFO", "[INFO] Use QUIT to end the program."},
			{"PATH_INFO", "[INFO] The program will put your\n"
										"       files into a newly created\n" 
										"       folder with the same name\n"
										"       as the files"},
			{"ROOT_INFO", "[INFO] If you really want to create\n"
										"       files on your OS root directory\n"
										"       then specify it with using '//'"},
		};

		inline static const unordered_map<string, string> FILE_CONTENTS =
		{
			{"IFNDEF", "#ifndef "},
			{"DEFINE", "#define "},
			{"ENDIF", "#endif "},
			{"HPP", "_HPP"},
			{"H", "_H"},
			{"INCLUDE", "#include "},
			{"CLASS", "class "},
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