#ifndef _PX_PARSER_SCRIPTS_DOCUMENT_HEADER_
#define _PX_PARSER_SCRIPTS_DOCUMENT_HEADER_

#include <PxParser/Document/PxParserDocument.hpp>

namespace PxParser
{
	class ScriptsDocument final : public Document
	{
	public:
		ScriptsDocument();
		~ScriptsDocument() = default;

	public:
		void LoadFromFile(const std::string& fullPath) override;
		void SaveToFile(const std::string& fullPath) override;

	private:
		void SaveNode(const NodePtr& node, std::string& data);
		void SaveValue(const Node::ValuePtr& value, std::string& data);
		void SaveCondition(const Node::ConditionPtr& condition, std::string& data);

	private:
		std::string GetTabsByDepth() const;

	private:
		int _depth;
	};
}

#endif // _PX_PARSER_SCRIPTS_DOCUMENT_HEADER_
