#include "filecreator.hpp"

FileCreator::FileCreator() : file_path_string_(""), file_path_(""), is_cpp_(false), with_class_(nullopt), 
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

	createFilePath();
	if(running_ == States::QUIT) return;

	checkProgramingLanguage();
	if(running_ == States::QUIT) return;

	while(running_ != States::QUIT)
	{
		createFile();
	}
}

void FileCreator::createFilePath()
{
	serializer_.writeLine();
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

	file_path_ = current_path() / path(file_path_string_).relative_path();
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
	bool language_selector_running = true;
	
	while(language_selector_running == true)
	{
		serializer_.writeLine();
		serializer_.writeMessage("C_OR_CPP");
		serializer_.writeMessage("INPUT_WAIT");

		string input = "";
		getline(cin, input);

		Utils::allSmall(input);
		if(input == "quit")
		{
			running_ = States::QUIT;
			language_selector_running = false;
			continue;
		}

		if(input == "c" || input == "")
		{
			is_cpp_ = false;
			language_selector_running = false;
			continue;
		}

		if(input == "p" || input == "cpp" || input == "+")
		{
			is_cpp_ = true;
			classEnabler();
			language_selector_running = false;
			continue;
		}

		serializer_.writeError("INVALID_LANGUAGE");
	}
}

void FileCreator::createFile()
{
	serializer_.writeLine();
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

	createCFiles(file_name);
}

void FileCreator::createClassForCpp(Serializer &h_serializer, string &file_name)
{
	h_serializer.writeLine();
	h_serializer.writeFileContent("CLASS");
	h_serializer.writeLine(file_name);
	h_serializer.writeLine("{");
	h_serializer.writeFileContent("PRIVATE");
	h_serializer.writeLine();
	h_serializer.writeLine();
	h_serializer.writeFileContent("PUBLIC");
	h_serializer.writeLine();
	h_serializer.writeLine();
	h_serializer.writeLine("};");
	h_serializer.writeLine();
}

void FileCreator::createCFiles(string file_name)
{
	string c_extension = (is_cpp_ == true) ? ".cpp" : ".c";
	string h_extension = (is_cpp_ == true) ? ".hpp" : ".h";
	string big_h_extension = h_extension.substr(1);
	Utils::allBig(big_h_extension);

	if(file_name.empty() == true)
	{
		serializer_.writeError("INVALID_FILENAME");
		return;
	}

	path file_name_path = file_name;

	if(file_name_path.relative_path().parent_path() != "")
	{
		serializer_.writeError("INVALID_FILENAME");
		return;
	}

	path new_path = file_path_ / file_name_path.relative_path();
	create_directories(new_path);

	path c_file_path = new_path / (file_name + c_extension);
	path h_file_path = new_path / (file_name + h_extension);

	if((exists(c_file_path) && file_size(c_file_path) > 0) || (exists(h_file_path) && file_size(h_file_path) > 0))
	{
		serializer_.writeError("FILE_NO_EMPTY");
		return;
	}

	ofstream c_file(c_file_path);
	ofstream h_file(h_file_path);

	if(c_file.is_open() == false || h_file.is_open() == false)
	{
		serializer_.writeError("NO_OPEN");
		return;
  }
	
	Serializer c_serializer(c_file);
	Serializer h_serializer(h_file);

	string file_name_copy = file_name;
	Utils::allBig(file_name_copy);

	writeCFile(h_serializer, c_serializer, file_name_copy, big_h_extension, file_name, h_extension);
}

void FileCreator::classEnabler()
{
	bool class_decision_running = true;

	while(class_decision_running == true)
	{
		serializer_.writeLine();
		serializer_.writeMessage("CLASS_OR_NO_CLASS");
		serializer_.writeMessage("INPUT_WAIT");

		string input = "";
		getline(cin, input);
		Utils::allSmall(input);

		if(input == "quit")
		{
			running_ = States::QUIT;
			class_decision_running = false;
			continue;
		}

		if(input == "no" || input == "" || input == "n")
		{
			with_class_ = false;
			class_decision_running = false;
			continue;
		}

		if(input == "yes" || input == "y")
		{
			with_class_ = true;
			class_decision_running = false;
			continue;
		}

		serializer_.writeError("INVALID_CLASS");
	}
}

void FileCreator::writeCFile(Serializer &h_serializer, Serializer &c_serializer, 
		string file_name_copy, string big_h_extension, string file_name, string h_extension)
{
	h_serializer.writeFileContent("IFNDEF");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent(big_h_extension);
	h_serializer.writeLine();

	h_serializer.writeFileContent("DEFINE");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent(big_h_extension);
	h_serializer.writeLine();

	(with_class_ == true) ? createClassForCpp(h_serializer, file_name) : h_serializer.writeLine();

	h_serializer.writeFileContent("ENDIF");
	h_serializer.write("// ");
	h_serializer.write(file_name_copy);
	h_serializer.writeFileContent(big_h_extension);
	h_serializer.writeLine();

	c_serializer.writeFileContent("INCLUDE");
	c_serializer.writeLine("\"" + file_name + h_extension + "\"");
	c_serializer.writeLine();
}