//----------------------------------------------------------------------------------------------------------------------
/// This is the first version of cpp-hpp-file-creator it is very basic but it works :)
/// This version supports absolute paths if the user types in more than one slash at the beginning when defining
/// the path where they want their files made
//----------------------------------------------------------------------------------------------------------------------

#include "base.hpp"
#include "classes/filecreator/filecreator.hpp"

int main(void)
{
	FileCreator program = FileCreator();
	program.run();

	return 0;
}