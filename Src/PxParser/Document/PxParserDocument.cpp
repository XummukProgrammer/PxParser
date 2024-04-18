#include "PxParserDocument.hpp"

#include <PxParser/Lexer/PxParserLexer.hpp>

namespace PxParser
{
	Document::Document()
		: _root(std::make_shared<Node>("Root"))
	{
		_stack.push(_root);
	}

	Document::NodePtr Document::GetRoot() const
	{
		return _root;
	}
}
