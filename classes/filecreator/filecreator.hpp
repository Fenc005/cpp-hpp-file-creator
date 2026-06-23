#ifndef FILECREATOR_HPP
#define FILECREATOR_HPP

#include "../../base.hpp"
#include "../serializer/serializer.hpp"

enum class States
{
	QUIT,
	DEFAULT,
};

class FileCreator
{
	private:
		string file_path_string_;
		path file_path_;

		bool is_cpp_;
		optional<bool> with_class_;
		Serializer serializer_;
		States running_;

	public:
		FileCreator();

		FileCreator(const FileCreator&) = delete;

		~FileCreator() = default;

		void run();

		void createFilePath();
		void checkProgramingLanguage();
		void createFile();
		void createClassForCpp(Serializer &h_serializer, string &file_name);
		void createCFiles(string file_name);
		void classEnabler();
		void writeCFile(Serializer &h_serializer, Serializer &c_serializer, 
		string file_name_copy, string big_h_extension, string file_name, string h_extension);
};

#endif //FILECREATOR_HPP