#ifndef _PX_PARSER_DOCUMENT_HEADER_
#define _PX_PARSER_DOCUMENT_HEADER_

#include <PxParser/Document/PxParserNode.hpp>

#include <stack>
#include <string>

namespace PxParser
{
	class Document final
	{
	public:
		using NodePtr = std::shared_ptr<Node>;

	public:
		Document();
		~Document() = default;

	public:
		NodePtr GetRoot() const;

	public:
		void LoadFromFile(const std::string& fullPath);

	private:
		NodePtr _root;
		std::stack<NodePtr> _stack;
	};
}

#endif // _PX_PARSER_DOCUMENT_HEADER_
