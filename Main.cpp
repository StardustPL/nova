#include <iostream>
#include <limits>

//psi: PolyStatic Interpreter
//"psi" -> interactive interpreter
//"psi liquify file.ps[liquid,solid]" -> interactive interpreter starting with environment from file.psliquid or file.pssolid
//"psi solidify file.psliquid" -> compile file.psliquid into file.pssolid
//"psi melt file.pssolid" -> extract interface information from file.pssolid to file.psgas

int main(int nargs, char const *const *args)
{
	for(unsigned i = 0; i < nargs; ++i)
	{
		std::cout << args[i] << std::endl;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
