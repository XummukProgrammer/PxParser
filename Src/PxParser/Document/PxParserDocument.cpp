﻿#include "PxParserDocument.hpp"

#include <PxParser/Lexer/PxParserLexer.hpp>

namespace PxParser
{
	Document::Document()
		: _root(std::make_shared<Node>("Root"))
	{
		_stack.push(_root);
	}

	Document::NodePtr Document::GetRoot() const
	{
		return _root;
	}

	void Document::LoadFromFile(const std::string& fullPath)
	{
		Lexer lexer;
		lexer.LoadFromFile(fullPath);
		lexer.DebugPrintTokens();

		auto begin = lexer.GetTokensBegin();
		auto end = lexer.GetTokensEnd();

		for (;;)
		{
			if (begin == end)
			{
				break;
			}

			if ((*begin)->GetType() == Token::Type::String)
			{
				std::string name = (*begin)->GetText();

				++begin;

				if (begin == end)
				{
					break;
				}

				if ((*begin)->GetType() == Token::Type::Operator)
				{
					if ((*begin)->GetText() == "=")
					{
						++begin;

						if (begin == end)
						{
							break;
						}

						if ((*begin)->GetType() == Token::Type::Operator)
						{
							if ((*begin)->GetText() == "{")
							{
								auto newChild = std::make_shared<Node>(name);
								_stack.top()->AddChild(newChild);

								_stack.push(newChild);

								++begin;
							}
						}
						else if ((*begin)->GetType() == Token::Type::String || (*begin)->GetType() == Token::Type::Number)
						{
							std::string value = (*begin)->GetText();

							_stack.top()->AddValue(std::make_shared<Value>(name, value));

							++begin;
						}
					}
					else if ((*begin)->GetText() == ">" || (*begin)->GetText() == "<")
					{
						Condition::Type conditionType{};

						if ((*begin)->GetText() == ">")
						{
							conditionType = Condition::Type::More;
						}
						else if ((*begin)->GetText() == "<")
						{
							conditionType = Condition::Type::Less;
						}

						++begin;

						if (begin == end)
						{
							break;
						}

						if ((*begin)->GetType() == Token::Type::String || (*begin)->GetType() == Token::Type::Number)
						{
							std::string value = (*begin)->GetText();

							_stack.top()->AddCondition(std::make_shared<Condition>(name, conditionType, value));

							++begin;
						}
					}
				}
			}
			else if ((*begin)->GetType() == Token::Type::Operator)
			{
				if ((*begin)->GetText() == "}")
				{
					_stack.pop();

					++begin;
				}
			}
		}
	}
}
