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

	private:
		void SaveValues(std::string& data);
		void SaveValue(const Node::ValuePtr& value, std::string& data);
		void SaveHeader(const Node::ValuePtr& value, std::string& data);
	};
}

#endif // _PX_PARSER_LOCALIZATION_DOCUMENT_HEADER_
