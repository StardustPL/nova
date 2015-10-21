#include <json.h>

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <streambuf>

int main(int, char const *const *plain_args)
{
	std::basic_string<char const *> const temp {plain_args};
	std::vector<std::string> const args {std::begin(temp)+1, std::end(temp)};

	if(args.size() > 1)
	{
		std::cerr << "You need to pass only the path to the .json file of your choice, or execute this program in a directory containing a file named \"stardust.json\"" << std::endl;
		return EXIT_FAILURE;
	}
	std::string const &json_filename = (args.empty()? "stardust.json" : args[0]);

	if(std::ifstream json_file {json_filename})
	{
		std::string const json_string ((std::istreambuf_iterator<char>(json_file)), std::istreambuf_iterator<char>());
		json_settings json_options {0U, json_enable_comments, nullptr, nullptr, nullptr, 0U};
		char json_error[json_error_max];
		if(json_value *json = json_parse_ex(&json_options, json_string.c_str(), json_string.size(), json_error))
		{
			//
		}
		else
		{
			std::cerr << "Error: unable to load \"" << json_filename << "\": " << json_error << std::endl;
			return EXIT_FAILURE;
		}
	}
	else
	{
		std::cerr << "Error: unable to access \"" << json_filename << '"' << std::endl;
		return EXIT_FAILURE;
	}
}
