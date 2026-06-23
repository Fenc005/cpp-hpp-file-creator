#include "filecreator.hpp"

FileCreator::FileCreator() : file_path_string_(""), file_path_(""), is_cpp_(false), with_class_(false), 
	serializer_(cout), running_(States::DEFAULT) {}

void FileCreator::run()
{
	serializer_.writeMessage("WELCOME_LINE");
	serializer_.writeMessage("WELCOME_MSSG");
	serializer_.writeMessage("WELCOME_LINE");
	serializer_.writeLine();
	serializer_.writeMessage("QUIT_INFO");
	serializer_.writeLine();
	serializer_.writeMessage("PATH_INFO");
	serializer_.writeLine();
	serializer_.writeMessage("ROOT_INFO");
	serializer_.writeLine();

	createFilePath();
	if(running_ == States::QUIT) return;

	checkProgramingLanguage();
	if(running_ == States::QUIT) return;

	while (running_ != States::QUIT)
	{
		createFile();
	}
}

void FileCreator::createFilePath()
{
	serializer_.writeMessage("FILE_PATH");
	serializer_.writeMessage("INPUT_WAIT");

	getline(cin, file_path_string_);

	string file_path_string_copy = file_path_string_;
	Utils::allSmall(file_path_string_copy);
	if(file_path_string_copy == "quit")
	{
		running_ = States::QUIT;
		return;
	}

	if(file_path_string_.empty() == false && file_path_string_.at(0) == '/')
	{
		if(file_path_string_.size() == 1)
		{
			file_path_string_ = DEFAULT_PATH;
		}
		else
		{
			file_path_string_.erase(0, 1);
		}
	}

	file_path_ = (file_path_string_.empty() == true) ? DEFAULT_PATH : file_path_string_;
	file_path_ = file_path_.lexically_normal();

	if(exists(file_path_) == false)
	{
		create_directories(file_path_);
	}

	if(exists(file_path_) == false)
	{
		serializer_.writeError("INVALID_FILEPATH");
		running_ = States::QUIT;
		return;
	}
}

void FileCreator::checkProgramingLanguage()
{
	serializer_.writeMessage("C_OR_CPP");
	serializer_.writeMessage("INPUT_WAIT");

	string input = "";
	getline(cin, input);

	Utils::allSmall(input);
	if(input == "quit")
	{
		running_ = States::QUIT;
		return;
	}

	if(input != "c" && input != "p")
	{
		serializer_.writeError("INVALID_LANGUAGE");
		return;
	}

	if(input == "p")
	{
		is_cpp_ = true;
	}
}

void FileCreator::createFile()
{
	//temporary mode
	is_cpp_ = false;

	serializer_.writeMessage("INPUT_MSSG");
	serializer_.writeMessage("INPUT_WAIT");

	string file_name = "";
	getline(cin, file_name);

	string file_name_copy = file_name;
	Utils::allSmall(file_name_copy);
	if(file_name_copy == "quit")
	{
		running_ = States::QUIT;
		return;
	}	

	if(is_cpp_ == true)
	{
		createCPlusPlusFiles(file_name);
	}
	else
	{
		createCFiles(file_name);
	}
}

void FileCreator::createCPlusPlusFiles(string file_name)
{
	return;
}

void FileCreator::createCFiles(string file_name)
{
	path new_path = file_path_ / file_name;
	create_directories(new_path);

	ofstream c_file(new_path/(file_name + ".c"));
	ofstream h_file(new_path/(file_name + ".h"));

	if (!c_file.is_open() || !h_file.is_open()) {
      serializer_.writeError("NO_OPEN");
      return;
  }
	
	Serializer c_serializer(c_file);
	Serializer h_serializer(h_file);

	string file_name_copy = file_name;
	Utils::allBig(file_name_copy);

	h_serializer.writeFileContent("IFNDEF");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent("H");
	h_serializer.writeLine();

	h_serializer.writeFileContent("DEFINE");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent("H");
	h_serializer.writeLine();

	h_serializer.writeLine();

	h_serializer.writeFileContent("ENDIF");
	h_serializer.write("// ");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent("H");

	c_serializer.writeFileContent("INCLUDE");
	c_serializer.writeLine("\"" + file_name + ".h\"");
	c_serializer.writeLine();
}