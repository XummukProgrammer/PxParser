#include "PxParserStringHelper.hpp"

namespace PxParser::Helpers
{
	std::string GetStringAtEnd(const std::string& str, char prevSymbol)
	{
		size_t begin = str.find_last_of(prevSymbol);
		if (begin != std::string::npos)
		{
			return str.substr(begin + 1);
		}
		return "";
	}
}
