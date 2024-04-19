#include "PxParserLexer.hpp"

#include <PxParser/Helpers/PxParserDebugPrinters.hpp>
#include <PxParser/Helpers/PxParserFilesHelper.hpp>

namespace PxParser
{
	const Lexer::Tokens& Lexer::GetTokens() const
	{
		return _tokens;
	}

	Lexer::TokensConstIterator Lexer::GetTokensBegin() const
	{
		return _tokens.begin();
	}

	Lexer::TokensConstIterator Lexer::GetTokensEnd() const
	{
		return _tokens.end();
	}

	void Lexer::LoadFromFile(const std::string& fullPath)
	{
		std::string data;
		Helpers::ReadFromFile(fullPath, data);
		Process(data);
	}

	void Lexer::Process(const std::string& text)
	{
		auto beginText = text.begin();
		auto endText = text.end();

		for (; ;)
		{
			if (beginText == endText)
			{
				break;
			}

			if (IsEmpty(*beginText))
			{
				++beginText;
			}
			else if (IsComment(*beginText))
			{
				CommentProcess(beginText, endText);
			}
			else if (*beginText == '\"')
			{
				std::string text = "";
				
				for (; ;)
				{
					++beginText;

					if (beginText == endText)
					{
						break;
					}

					if (*beginText != '\"')
					{
						text += *beginText;
					}
					else
					{
						break;
					}
				}

				_tokens.push_back(std::make_shared<Token>(std::move(text), true, Token::Type::String));

				++beginText;
			}
			else if (IsOperator(*beginText))
			{
				OperatorProcess(beginText, endText);
			}
			else if (IsNumber(*beginText))
			{
				NumberProcess(beginText, endText);
			}
			else if (!IsEmpty(*beginText))
			{
				TextProcess(beginText, endText);
			}
		}
	}

	void Lexer::DebugPrintTokens()
	{
		Helpers::PrintTokens(_tokens);
	}

	bool Lexer::IsOperator(char symbol)
	{
		return symbol == '='
			|| symbol == '{'
			|| symbol == '}'
			|| symbol == '>'
			|| symbol == '<'
			|| symbol == ':';
	}

	bool Lexer::IsNumber(char symbol)
	{
		return symbol >= '0' && symbol <= '9' || symbol == '.' || symbol == '-';
	}

	bool Lexer::IsEmpty(char symbol)
	{
		return symbol == ' ' || symbol == '\t' || symbol == '\n';
	}

	bool Lexer::IsComment(char symbol)
	{
		return symbol == '#';
	}

	void Lexer::OperatorProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText)
	{
		std::string text = std::string{ *beginText };

		_tokens.push_back(std::make_shared<Token>(std::move(text), false, Token::Type::Operator));

		++beginText;
	}

	void Lexer::NumberProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText)
	{
		std::string text = std::string{ *beginText };

		for (; ;)
		{
			++beginText;

			if (IsNumber(*beginText))
			{
				text += *beginText;
			}
			else
			{
				break;
			}
		}

		_tokens.push_back(std::make_shared<Token>(std::move(text), false, Token::Type::Number));
	}

	void Lexer::TextProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText)
	{
		std::string text = std::string{ *beginText };

		for (; ;)
		{
			++beginText;

			if (beginText == endText)
			{
				break;
			}

			if (!IsEmpty(*beginText) && !IsOperator(*beginText))
			{
				text += *beginText;
			}
			else
			{
				break;
			}
		}

		_tokens.push_back(std::make_shared<Token>(std::move(text), false, Token::Type::String));
	}

	void Lexer::CommentProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText)
	{
		do
		{
			++beginText;
		} 
		while (*beginText != '\n');
	}
}
