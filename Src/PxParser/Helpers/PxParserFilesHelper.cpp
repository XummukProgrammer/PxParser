#include "PxParserFilesHelper.hpp"

#include <fstream>
#include <sstream>
#include <filesystem>

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

	std::vector<std::string> GetAllFilesInFolder(const std::string& folderPath)
	{
		std::vector<std::string> paths;

		for (const auto& entry : std::filesystem::directory_iterator(folderPath))
		{
			paths.push_back(entry.path().string());
		}

		return paths;
	}

	std::vector<std::string> GetAllFoldersInFolder(const std::string& folderPath)
	{
		std::vector<std::string> paths;

		for (const auto& entry : std::filesystem::directory_iterator(folderPath))
		{
			if (entry.is_directory())
			{
				paths.push_back(entry.path().string());
			}
		}

		return paths;
	}
}
