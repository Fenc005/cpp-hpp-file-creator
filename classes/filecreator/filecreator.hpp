#ifndef FILECREATOR_HPP
#define FILECREATOR_HPP

#include "../../base.hpp"

class filecreator
{
	private:
		string file_path_;
		string input_;
		bool is_cpp_;
		bool with_class_;

	public:
		filecreator();

		filecreator(const filecreator&) = delete;

		~filecreator() = default;

		void run();

		void creatorLoop();

		bool checkInput(string &input, string message_key);

		void createFile();

		bool cOrCpp();

		bool classOrNoClass();
};

#endif //FILECREATOR_HPP