#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

//god: Cosmos Compiler/Interpreter
//"god" -> interactive interpreter
//"god liquefy file.c[liquid,solid]..." -> interactive interpreter starting with environment from file.cliquid or file.csolid (*.c*id)
//"god solidify file.cliquid..." -> compile file.cliquid into file.csolid
//"god melt file.csolid..." -> extract interface information from file.csolid to file.cgas

int main(int nargs, char const *const *args)
{
//	auto &WaitForEnter = []{ std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); };
	std::vector<std::string> argv (args+1, args+nargs);

	if(argv.size() == 0)
	{
		//interactive
	}
	else
	{
		std::string command = argv.front();
		argv.erase(std::begin(argv));
		std::transform(command.begin(), command.end(), command.begin(), ::tolower);
		if(command == "liquefy")
		{
			//
		}
		else if(command == "solidify")
		{
			//
		}
		else if(command == "melt")
		{
			//
		}
		else
		{
			std::cout << '"' << command << "\" is not a command" << std::endl;
		}
	}
}
