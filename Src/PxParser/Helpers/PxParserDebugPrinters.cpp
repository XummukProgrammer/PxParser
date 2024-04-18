#include "PxParserDebugPrinters.hpp"

#include <PxParser/Helpers/PxParserConverters.hpp>

#include <iostream>

namespace PxParser::Helpers
{
	void PrintToken(const Token& token)
	{
		std::cout << "TOKEN INFO:\t" << token.GetText() << " | " << TokenTypeToString(token.GetType()) << std::endl;
	}
}
