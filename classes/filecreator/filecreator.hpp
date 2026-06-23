#ifndef FILECREATOR_HPP
#define FILECREATOR_HPP

#include "../../base.hpp"
#include "../serializer/serializer.hpp"

class FileCreator
{
	private:
		string file_path_;
		string input_;
		bool is_cpp_;
		bool with_class_;
		Serializer serializer_;

	public:
		FileCreator();

		FileCreator(const FileCreator&) = delete;

		~FileCreator() = default;

		void run();

		void creatorLoop();

		bool checkInput(string &input, string message_key);

		void createFile();

		bool cOrCpp();

		bool classOrNoClass();
};

#endif //FILECREATOR_HPP