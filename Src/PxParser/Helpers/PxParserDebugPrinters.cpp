#include "PxParserDebugPrinters.hpp"

#include <PxParser/Helpers/PxParserConverters.hpp>

#include <iostream>

namespace PxParser::Helpers
{
	void PrintToken(const std::shared_ptr<Token>& token)
	{
		std::cout << "TOKEN INFO:\t" << token->GetText() << " | " << TokenTypeToString(token->GetType()) << std::endl;
	}

	void PrintTokens(const std::vector<std::shared_ptr<Token>> tokens)
	{
		std::cout << "Number of tokens: " << tokens.size() << std::endl;

		std::cout << "================================" << std::endl;
		for (const auto& token : tokens)
		{
			Helpers::PrintToken(token);
		}
		std::cout << "================================" << std::endl;
	}
}
