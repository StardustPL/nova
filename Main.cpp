#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

//psi: PolyStatic Interpreter
//"psi" -> interactive interpreter
//"psi liquify file.ps[liquid,solid]..." -> interactive interpreter starting with environment from file.psliquid or file.pssolid (*.ps*id)
//"psi solidify file.psliquid..." -> compile file.psliquid into file.pssolid
//"psi melt file.pssolid..." -> extract interface information from file.pssolid to file.psgas

void Liquify(std::vector<std::string> const &files = std::vector<std::string>());
void Solidify(std::vector<std::string> const &files);
void Melt(std::vector<std::string> const &files);

int main(int nargs, char const *const *args_)
{
//	auto &WaitForEnter = []{ std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); };
	if(nargs < 1) return -1;
	std::vector<std::string> args;
	std::for_each(args_+1, args_+nargs, [&args](char const *s)
	{
		args.push_back(s);
	});

	if(args.size() == 0)
	{
		Liquify();
	}
	else
	{
		std::string command = args[0];
		args.pop_front();
		std::transform(command.begin(), command.end(), command.begin(), ::tolower);
		if(command == "liquify")
		{
			Liquify(args);
		}
		else if(command == "solidify")
		{
			Solidify(args);
		}
		else if(command == "melt")
		{
			Melt(args);
		}
		else
		{
			std::cout << '"' << command << "\" is not a command" << std::endl;
		}
	}
}
