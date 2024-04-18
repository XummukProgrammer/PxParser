#ifndef _PX_PARSER_DOCUMENT_HEADER_
#define _PX_PARSER_DOCUMENT_HEADER_

#include <PxParser/Document/PxParserNode.hpp>

#include <stack>
#include <string>

namespace PxParser
{
	class Document
	{
	public:
		using NodePtr = std::shared_ptr<Node>;

	public:
		Document();
		virtual ~Document() = default;

	public:
		NodePtr GetRoot() const;

	public:
		virtual void LoadFromFile(const std::string& fullPath) {}
		virtual void SaveToFile(const std::string& fullPath) {}

	protected:
		NodePtr _root;
		std::stack<NodePtr> _stack;
	};
}

#endif // _PX_PARSER_DOCUMENT_HEADER_
