#include <string>
#include <vector>
#include <algorithm>

int main(int, char const *const *plain_args)
{
	std::basic_string<char const *> const temp {plain_args};
	std::vector<std::string> const args {std::begin(temp)+1, std::end(temp)};

	for(auto const &arg : args)
	{
		std::string temp = arg;
		std::transform(std::begin(temp), std::end(temp), std::begin(temp), ::tolower);
		if(temp == "why")
		{
			return 42;
		}
	}
}
