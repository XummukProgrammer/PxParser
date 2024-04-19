#include "PxParserToken.hpp"

namespace PxParser
{
	Token::Token(const std::string& text, bool isStrong, Type type)
		: _text(text, isStrong)
		, _type(type)
	{
	}

	const Data::String& Token::GetText() const
	{
		return _text;
	}

	Token::Type Token::GetType() const
	{
		return _type;
	}
}
