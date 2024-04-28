#include "PxParserMod.hpp"

#include <PxParser/Helpers/PxParserFilesHelper.hpp>
#include <PxParser/Helpers/PxParserStringHelper.hpp>
#include <PxParser/Document/PxParserLocalizationDocument.hpp>

namespace PxParser
{
	void Localizations::Update(const std::string& path)
	{
		const auto& localeFolders = Helpers::GetAllFoldersInFolder(path);
		for (const auto& localeFolder : localeFolders)
		{
			std::string localeName = Helpers::GetStringAtEnd(localeFolder);
			if (localeName != "replace")
			{
				const auto& localeFiles = Helpers::GetAllFilesInFolder(localeFolder);
				for (const auto& localeFile : localeFiles)
				{
					LocalizationDocument locDoc;
					locDoc.LoadFromFile(localeFile);

					const auto& data = locDoc.GetData();
					for (const auto& element : data)
					{
						_localizations[localeName][element.first] = element.second;
					}
				}
			}
		}
	}

	std::string Localizations::GetTransition(const std::string& localeName, const std::string& transitionName) const
	{
		auto locIt = _localizations.find(localeName);
		if (locIt != _localizations.end())
		{
			auto transitionIt = locIt->second.find(transitionName);
			if (transitionIt != locIt->second.end())
			{
				return transitionIt->second;
			}
		}
		return "!!!NO_FOUND!!!";
	}
}
