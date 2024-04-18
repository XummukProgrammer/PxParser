﻿#include "PxParserToken.hpp"

namespace PxParser
{
	Token::Token(const std::string& text, Type type)
		: _text(text)
		, _type(type)
	{
	}

	std::string Token::GetDebug() const
	{
		std::string outString;

		outString += "TOKEN INFO:\t";
		outString += _text;
		outString += " | ";
		outString += TypeToString(_type);

		return outString;
	}

	std::string Token::TypeToString(Type type)
	{
		switch (type)
		{
		case Type::Number:
			return "Number";

		case Type::Operator:
			return "Operator";

		case Type::String:
			return "String";
		}
		return "!!!UNKNOWN!!!";
	}
}