#ifndef FILECREATOR_HPP
#define FILECREATOR_HPP

#include "../../base.hpp"
#include "../serializer/serializer.hpp"

enum class States
{
	FALSE,
	TRUE,
	QUIT,
	DEFAULT,
};

class FileCreator
{
	private:
		string file_path_string_;
		path file_path_;

		bool is_cpp_;
		bool with_class_;
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
};

#endif //FILECREATOR_HPP