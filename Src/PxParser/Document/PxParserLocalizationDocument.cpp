#include "PxParserLocalizationDocument.hpp"

#include <PxParser/Lexer/PxParserLexer.hpp>
#include <PxParser/Helpers/PxParserFilesHelper.hpp>

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

		_root->CreateValue("LocalizationName")->SetValue((*begin)->GetText());
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
								_root->CreateValue(key)->SetValue(value);

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
		std::string data;
		SaveValues(data);

		Helpers::WriteToFile(fullPath, data);
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

	void LocalizationDocument::SaveValues(std::string& data)
	{
		for (auto it = _root->GetValuesBegin(); it != _root->GetValuesEnd(); ++it)
		{
			if ((*it)->GetName() != "LocalizationName")
			{
				SaveValue(*it, data);
			}
			else
			{
				SaveHeader(*it, data);
			}
		}
	}

	void LocalizationDocument::SaveValue(const Node::ValuePtr& value, std::string& data)
	{
		data += "  ";
		data += value->GetName();
		data += ":0 ";
		value->GetValue().Save(data);
		data += "\n";
	}

	void LocalizationDocument::SaveHeader(const Node::ValuePtr& value, std::string& data)
	{
		data += value->GetValue();
		data += ":\n";
	}
}
