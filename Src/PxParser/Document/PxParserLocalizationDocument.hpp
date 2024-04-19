#ifndef _PX_PARSER_LOCALIZATION_DOCUMENT_HEADER_
#define _PX_PARSER_LOCALIZATION_DOCUMENT_HEADER_

#include <PxParser/Document/PxParserDocument.hpp>

#include <map>

namespace PxParser
{
	class LocalizationDocument final : public Document
	{
	public:
		LocalizationDocument();
		~LocalizationDocument() = default;

	public:
		void LoadFromFile(const std::string& fullPath) override;
		void SaveToFile(const std::string& fullPath) override;

	public:
		std::map<std::string, std::string> GetData() const;
	};
}

#endif // _PX_PARSER_LOCALIZATION_DOCUMENT_HEADER_
