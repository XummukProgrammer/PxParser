#include "PxParserConverters.hpp"

namespace PxParser::Helpers
{
	std::string TokenTypeToString(Token::Type type)
	{
		switch (type)
		{
		case Token::Type::Number:
			return "Number";

		case Token::Type::Operator:
			return "Operator";

		case Token::Type::String:
			return "String";
		}
		return "!!!UNKNOWN!!!";
	}

	std::string ConditionTypeToString(Condition::Type type)
	{
		switch (type)
		{
		case Condition::Type::More:
			return ">";

		case Condition::Type::Less:
			return "<";
		}
		return "!!!UNKNOWN!!!";
	}
}
