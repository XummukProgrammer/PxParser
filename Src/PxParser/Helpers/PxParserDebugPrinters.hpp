#ifndef _PX_PARSER_DEBUG_PRINTERS_HEADER_
#define _PX_PARSER_DEBUG_PRINTERS_HEADER_

#include <PxParser/Lexer/PxParserToken.hpp>

#include <vector>
#include <memory>

namespace PxParser::Helpers
{
	void PrintToken(const std::shared_ptr<Token>& token);
	void PrintTokens(const std::vector<std::shared_ptr<Token>> tokens);
}

#endif // _PX_PARSER_DEBUG_PRINTERS_HEADER_
