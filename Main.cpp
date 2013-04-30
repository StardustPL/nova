#include <iostream>
#include <limits>

signed main(signed nargs,  char const *const *args)
{
	for(unsigned i = 0; i < nargs; ++i)
	{
		std::cout << args[i] << std::endl;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
