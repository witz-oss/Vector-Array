#include "error.h"

void error(const std::string& s)
{
	throw std::runtime_error(s);
}

void error(const std::string& s1, const std::string& s2)
{
	error(s1 + s2);
}
