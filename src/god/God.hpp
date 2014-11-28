#ifndef god_God_HeaderPlusPlus
#define god_God_HeaderPlusPlus

#include "stardust/Dust.hpp"

#include <istream>

namespace god
{
	Dust parse_dust(std::istream &dust);
}

#endif
