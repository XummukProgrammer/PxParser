#ifndef _PX_PARSER_FILES_HELPER_HEADER_
#define _PX_PARSER_FILES_HELPER_HEADER_

#include <string>

namespace PxParser::Helpers
{
	void WriteToFile(const std::string& fullPath, const std::string& data);
	void ReadFromFile(const std::string& fullPath, std::string& data);
}

#endif // _PX_PARSER_FILES_HELPER_HEADER_
