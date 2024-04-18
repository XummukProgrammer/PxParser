#include "PxParserToken.hpp"

namespace PxParser
{
	Token::Token(const std::string& text, Type type)
		: _text(text)
		, _type(type)
	{
	}

	const std::string& Token::GetText() const
	{
		return _text;
	}

	Token::Type Token::GetType() const
	{
		return _type;
	}
}
