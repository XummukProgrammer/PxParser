#ifndef _PX_PARSER_FILE_SYSTEM_HEADER_
#define _PX_PARSER_FILE_SYSTEM_HEADER_

#include <PxParser/FileSystem/PxParserModFile.hpp>

#include <string>
#include <vector>
#include <memory>

namespace PxParser
{
	class FileSystem final
	{
	public:
		using ModFilePtr = std::shared_ptr<ModFile>;
		using ModFiles = std::vector<ModFilePtr>;
		using ModFilesConstIterator = ModFiles::const_iterator;

	public:
		FileSystem(const std::string& documentsFolderPath);
		~FileSystem() = default;

	public:
		void Update();

	public:
		std::string GetModFolderPath() const;

	public:
		const ModFiles& GetModFiles() const;
		ModFilesConstIterator GetModFilesBegin() const;
		ModFilesConstIterator GetModFilesEnd() const;

		ModFilePtr GetModFileByName(const std::string& name) const;

	private:
		void UpdateModFiles();

	private:
		std::string _documentsFolderPath;
		ModFiles _modFiles;
	};
}

#endif // _PX_PARSER_FILE_SYSTEM_HEADER_
