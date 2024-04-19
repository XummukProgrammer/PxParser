#include "PxParserFilesHelper.hpp"

#include <fstream>
#include <sstream>

namespace PxParser::Helpers
{
	void WriteToFile(const std::string& fullPath, const std::string& data)
	{
		std::ofstream fout(fullPath);
		if (fout.is_open())
		{
			fout << data;
			fout.close();
		}
	}

	void ReadFromFile(const std::string& fullPath, std::string& data)
	{
		std::ifstream fin(fullPath);
		if (fin.is_open())
		{
			std::ostringstream sstr;
			sstr << fin.rdbuf();
			data = sstr.str();
			fin.close();
		}
	}
}
