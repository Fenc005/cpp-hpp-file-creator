#include "filecreator.hpp"

FileCreator::FileCreator() : file_path_(""), input_(""), is_cpp_(false), with_class_(false), serializer_(cout) {}

void FileCreator::run()
{
	serializer_.writeMessage("WELCOME_LINE");
	serializer_.writeMessage("WELCOME_MSSG");
	serializer_.writeMessage("WELCOME_LINE");
	serializer_.writeLine();
	serializer_.writeMessage("QUIT_INFO");
	serializer_.writeLine();
	serializer_.writeMessage("FILE_PATH");
	serializer_.writeMessage("INPUT_WAIT");

	getline(cin, file_path_);
	if(checkInput(file_path_, "INVALID_FILEPATH") == true)
	{
		return;
	}

	cOrCpp();

	creatorLoop();
}

void FileCreator::creatorLoop()
{
	while(true)
	{
		serializer_.writeMessage("INPUT_MSSG");
		serializer_.writeMessage("INPUT_WAIT");

		getline(cin, input_);
		if(checkInput(input_, "INVALID_FILENAME"))
		{
			return;
		}

		classOrNoClass();

		createFile();
	}
}

bool FileCreator::checkInput(string &text, string message_key)
{
	if(text.size() <= 0)
	{
		serializer_.writeError(message_key);
		return true;
	}

	string text_copy = text;
	utils::AllSmall(text_copy);
	if(text_copy == "quit")
	{
		return true;
	}

	return false;
}

void FileCreator::createFile()
{
	return;
}

bool FileCreator::cOrCpp()
{
	string input = "";
	serializer_.writeMessage("C_OR_CPP");
	serializer_.writeMessage("INPUT_WAIT");
	getline(cin, input);

	utils::AllSmall(input);
	if(checkInput(input, "INVALID_LANGUAGE") == true)
	{
		return true;
	}

	if(input != "c" && input != "p")
	{
		serializer_.writeError("INVALID_LANGUAGE");
		return true;
	}

	if(input == "p")
	{
		is_cpp_ = true;
	}

	return false;
}

bool FileCreator::classOrNoClass()
{
	string input = "";
	serializer_.writeMessage("CLASS_OR_NO_CLASS");
	serializer_.writeMessage("INPUT_WAIT");
	getline(cin, input);

	utils::AllSmall(input);
	if(checkInput(input, "INVALID_CLASS") == true)
	{
		return true;
	}

	if(input != "yes" && input != "no")
	{
		serializer_.writeError("INVALID_CLASS");
		return false;
	}

	if(input == "yes")
	{
		with_class_ = true;
	}

	return false;
}