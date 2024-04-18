#ifndef _PX_PARSER_LEXER_HEADER_
#define _PX_PARSER_LEXER_HEADER_

#include <PxParser/Lexer/PxParserToken.hpp>

#include <vector>
#include <memory>

namespace PxParser
{
	class Lexer final
	{
	public:
		using TokenPtr = std::shared_ptr<Token>;
		using Tokens = std::vector<TokenPtr>;
		using TokensConstIterator = Tokens::const_iterator;

	public:
		Lexer() = default;
		~Lexer() = default;

	public:
		const Tokens& GetTokens() const;
		TokensConstIterator GetTokensBegin() const;
		TokensConstIterator GetTokensEnd() const;

	public:
		void LoadFromFile(const std::string& fullPath);

	public:
		void Process(const std::string& text);

	public:
		void DebugPrintTokens();

	private:
		bool IsOperator(char symbol);
		bool IsNumber(char symbol);
		bool IsEmpty(char symbol);
		bool IsComment(char symbol);

	private:
		void OperatorProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText);
		void NumberProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText);
		void TextProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText);
		void CommentProcess(std::string::const_iterator& beginText, std::string::const_iterator& endText);

	private:
		Tokens _tokens;
	};
}

#endif // _PX_PARSER_LEXER_HEADER_
