//----------------------------------------------------------------------------------------------------------------------
/// This is the first version of cpp-hpp-file-creator it is very basic but it works :)
//----------------------------------------------------------------------------------------------------------------------

#include "base.hpp"

void fileCreator(string &input)
{
  string filename = input;
  string header_guard = input;

  Base::FirstBigRestSmall(filename);
  Base::AllBig(header_guard);

  std::ofstream hpp_file(filename + ".hpp");
  std::ofstream cpp_file(filename + ".cpp");

  const string hpp_output = format("#ifndef {}_HPP\n#define {}_HPP\n\n#endif //{}_HPP", header_guard, header_guard, header_guard);
  const string cpp_output = format("#include \"{}.hpp\"\n", filename);

  hpp_file << hpp_output;
  cpp_file << cpp_output;

  cpp_file.close();
  hpp_file.close();
}

int main(void)
{
  cout << Base::WELCOME_LINE << endl << Base::WELCOME_MSSG << endl << Base::WELCOME_LINE << endl;
  bool running = true;

  while(running)
  {
    cout << endl << Base::PROMPT << endl;
    cout << Base::INPUT_WAIT;

    string input = "";
    getline(cin, input);

    if(Base::checkSize(input) == true)
    {
      continue;
    }

    Base::AllSmall(input);
    if(input == "quit")
    {
      running = false;
      continue;
    }

    fileCreator(input);
  }

  return 0;
}