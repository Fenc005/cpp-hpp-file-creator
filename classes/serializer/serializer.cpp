#include "serializer.hpp"
#include "../messages.hpp"

Serializer::Serializer(ostream &stream) : stream_(stream) {}

void Serializer::writeLine(const string text)
{
	stream_ << text << endl;
}

void Serializer::write(const string text)
{
	stream_ << text << flush;
}

void Serializer::writeError(const string &message)
{
	stream_ << endl << Messages::getErrorMessages(message) << endl;
}

void Serializer::writeMessage(const string &message)
{
	if(message == "INPUT_WAIT")
	{
		write(Messages::getNormalMessage(message));
		return;
	}
	
	writeLine(Messages::getNormalMessage(message));
}

void Serializer::writeFileContent(const string &message)
{
	write(Messages::getFileContents(message));
}
