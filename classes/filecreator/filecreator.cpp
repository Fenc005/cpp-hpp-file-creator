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
		cout << endl << Messages::getNormalMessage("INPUT_MSSG") << endl;
		cout << Messages::getNormalMessage("INPUT_WAIT");

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
		cout << endl << Messages::getErrorMessages(message_key) << endl;
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
	cout << endl << Messages::getNormalMessage("C_OR_CPP") << endl;
	cout << Messages::getNormalMessage("INPUT_WAIT");
	getline(cin, input);

	utils::AllSmall(input);
	if(checkInput(input, "INVALID_LANGUAGE") == true)
	{
		return true;
	}

	if(input != "c" && input != "p")
	{
		cout << endl << Messages::getErrorMessages("INVALID_LANGUAGE") << endl;
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
	cout << endl << Messages::getNormalMessage("CLASS_OR_NO_CLASS") << endl;
	cout << Messages::getNormalMessage("INPUT_WAIT");
	getline(cin, input);

	utils::AllSmall(input);
	if(checkInput(input, "INVALID_CLASS") == true)
	{
		return true;
	}

	if(input != "yes" && input != "no")
	{
		cout << endl << Messages::getErrorMessages("INVALID_CLASS") << endl;
		return false;
	}

	if(input == "yes")
	{
		with_class_ = true;
	}

	return false;
}