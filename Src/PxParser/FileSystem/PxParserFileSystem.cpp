#include "PxParserFileSystem.hpp"

#include <PxParser/Helpers/PxParserFilesHelper.hpp>
#include <PxParser/Document/PxParserScriptsDocument.hpp>

namespace PxParser
{
	FileSystem::FileSystem(const std::string& documentsFolderPath)
		: _documentsFolderPath(documentsFolderPath)
	{
	}

	void FileSystem::Update()
	{
		UpdateModFiles();
	}

	std::string FileSystem::GetModFolderPath() const
	{
		return _documentsFolderPath + "/mod/";
	}

	const FileSystem::ModFiles& FileSystem::GetModFiles() const
	{
		return _modFiles;
	}

	FileSystem::ModFilesConstIterator FileSystem::GetModFilesBegin() const
	{
		return _modFiles.begin();
	}

	FileSystem::ModFilesConstIterator FileSystem::GetModFilesEnd() const
	{
		return _modFiles.end();
	}

	FileSystem::ModFilePtr FileSystem::GetModFileByName(const std::string& name) const
	{
		for (const auto& modFile : _modFiles)
		{
			if (modFile->GetName() == name)
			{
				return modFile;
			}
		}
		return nullptr;
	}

	void FileSystem::UpdateModFiles()
	{
		_modFiles.clear();

		const auto& modFolderPath = GetModFolderPath();
		const auto& filesPaths = Helpers::GetAllFilesInFolder(modFolderPath);

		for (const auto& modPath : filesPaths)
		{
			ScriptsDocument modDocument;
			modDocument.LoadFromFile(modPath);

			auto newModFile = std::make_shared<ModFile>();
			newModFile->Load(modDocument.GetRoot());

			_modFiles.push_back(newModFile);
		}
	}
}
