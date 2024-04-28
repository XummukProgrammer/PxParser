#ifndef _PX_PARSER_STRING_HELPER_HEADER_
#define _PX_PARSER_STRING_HELPER_HEADER_

#include <string>

namespace PxParser::Helpers
{
	std::string GetStringAtEnd(const std::string& str, char prevSymbol = '/');
}

#endif // _PX_PARSER_STRING_HELPER_HEADER_
