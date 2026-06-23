//----------------------------------------------------------------------------------------------------------------------
/// This is the first version of cpp-hpp-file-creator it is very basic but it works :)
//----------------------------------------------------------------------------------------------------------------------

#include "base.hpp"
#include "classes/filecreator/filecreator.hpp"

int main(void)
{
	FileCreator program = FileCreator();
	program.run();

	return 0;
}