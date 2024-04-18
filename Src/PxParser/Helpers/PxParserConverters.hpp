#ifndef _PX_PARSER_CONVERTERS_HEADER_
#define _PX_PARSER_CONVERTERS_HEADER_

#include <PxParser/Lexer/PxParserToken.hpp>
#include <PxParser/Document/PxParserCondition.hpp>

namespace PxParser::Helpers
{
	std::string TokenTypeToString(Token::Type type);
	std::string ConditionTypeToString(Condition::Type type);
}

#endif // _PX_PARSER_CONVERTERS_HEADER_
