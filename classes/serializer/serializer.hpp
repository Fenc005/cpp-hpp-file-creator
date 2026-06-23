#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "../../base.hpp"

class Serializer
{
	private:
		ostream &stream_;

	public:
		Serializer(ostream &stream);
		Serializer(const Serializer&) = default;
		~Serializer() = default;

		void writeLine(const string text = "");
		void write(const string text);
		void writeError(const string &message);
		void writeMessage(const string &message);
		void writeFileContent(const string &message);
};

#endif //SERIALIZER_HPP