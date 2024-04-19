#include "PxParserLocalizationDocument.hpp"

#include <PxParser/Lexer/PxParserLexer.hpp>

namespace PxParser
{
	LocalizationDocument::LocalizationDocument()
	{
	}

	void LocalizationDocument::LoadFromFile(const std::string& fullPath)
	{
		Lexer lexer;
		lexer.LoadFromFile(fullPath);
		lexer.DebugPrintTokens();

		auto begin = lexer.GetTokensBegin();
		auto end = lexer.GetTokensEnd();

		++begin;
		++begin;

		for (;;)
		{
			if (begin == end)
			{
				break;
			}

			if ((*begin)->GetType() == Token::Type::String)
			{
				const auto& key = (*begin)->GetText();

				++begin;

				if (begin == end)
				{
					break;
				}

				if ((*begin)->GetType() == Token::Type::Operator)
				{
					if ((*begin)->GetText() == ":")
					{
						++begin;

						if (begin == end)
						{
							break;
						}

						if ((*begin)->GetType() == Token::Type::Number)
						{
							++begin;

							if (begin == end)
							{
								break;
							}

							if ((*begin)->GetType() == Token::Type::String)
							{
								const auto& value = (*begin)->GetText();

								_root->AddValue(std::make_shared<Value>(key, value));

								++begin;
							}
						}
					}
				}
			}
		}
	}

	void LocalizationDocument::SaveToFile(const std::string& fullPath)
	{
	}

	std::map<std::string, std::string> LocalizationDocument::GetData() const
	{
		std::map<std::string, std::string> data;

		for (auto it = _root->GetValuesBegin(); it != _root->GetValuesEnd(); ++it)
		{
			data[(*it)->GetName()] = (*it)->GetValue();
		}

		return data;
	}
}
