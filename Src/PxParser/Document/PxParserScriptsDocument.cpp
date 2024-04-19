#include "PxParserScriptsDocument.hpp"

#include <PxParser/Lexer/PxParserLexer.hpp>
#include <PxParser/Helpers/PxParserConverters.hpp>
#include <PxParser/Helpers/PxParserFilesHelper.hpp>

namespace PxParser
{
	ScriptsDocument::ScriptsDocument()
		: _depth(-2)
	{
	}

	void ScriptsDocument::LoadFromFile(const std::string& fullPath)
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
				const auto& name = (*begin)->GetText();

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
						else if ((*begin)->GetType() == Token::Type::String)
						{
							const auto& value = (*begin)->GetText();

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
							const auto& value = (*begin)->GetText();

							_stack.top()->AddCondition(std::make_shared<Condition>(name, conditionType, value));

							++begin;
						}
					}
					else if ((*begin)->GetText() == "}")
					{
						_stack.top()->AddValue(std::make_shared<Value>("Array", name));
					}
				}
				else if ((*begin)->GetType() == Token::Type::String)
				{
					_stack.top()->AddValue(std::make_shared<Value>("Array", name));

					do
					{
						_stack.top()->AddValue(std::make_shared<Value>("Array", (*begin)->GetText()));

						++begin;
					} 
					while ((*begin)->GetText() != "}");
				}
			}
			else if ((*begin)->GetType() == Token::Type::Number)
			{
				const auto& val = (*begin)->GetText();

				++begin;

				if (begin == end)
				{
					break;
				}

				if ((*begin)->GetType() == Token::Type::Operator)
				{
					if ((*begin)->GetText() == "}")
					{
						_stack.top()->AddValue(std::make_shared<Value>("Array", val));
					}
				}
				else if ((*begin)->GetType() == Token::Type::Number)
				{
					_stack.top()->AddValue(std::make_shared<Value>("Array", val));

					do
					{
						_stack.top()->AddValue(std::make_shared<Value>("Array", (*begin)->GetText()));

						++begin;
					} 
					while ((*begin)->GetText() != "}");
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

	void ScriptsDocument::SaveToFile(const std::string& fullPath)
	{
		std::string data;
		SaveNode(_root, data);

		Helpers::WriteToFile(fullPath, data);
	}

	void ScriptsDocument::SaveNode(const NodePtr& node, std::string& data)
	{
		++_depth;

		const auto& tabs = GetTabsByDepth();

		if (node->GetName() != "Root")
		{
			data += "\n";
			data += tabs;
			data += node->GetName();
			data += " = {";
		}

		for (auto it = node->GetValuesBegin(); it != node->GetValuesEnd(); ++it)
		{
			SaveValue(*it, data);
		}

		for (auto it = node->GetConditionsBegin(); it != node->GetConditionsEnd(); ++it)
		{
			SaveCondition(*it, data);
		}

		for (auto it = node->GetChildrenBegin(); it != node->GetChildrenEnd(); ++it)
		{
			SaveNode(*it, data);
		}

		if (node->GetName() != "Root")
		{
			data += "\n";
			data += tabs;
			data += "}";
		}

		--_depth;
	}

	void ScriptsDocument::SaveValue(const Node::ValuePtr& value, std::string& data)
	{
		++_depth;

		data += "\n";
		data += GetTabsByDepth();

		if (value->GetName() != "Array")
		{
			data += value->GetName();
			data += " = ";
		}

		value->GetValue().Save(data);

		--_depth;
	}

	void ScriptsDocument::SaveCondition(const Node::ConditionPtr& condition, std::string& data)
	{
		++_depth;

		data += "\n";
		data += GetTabsByDepth();
		data += condition->GetName();
		data += " ";
		data += Helpers::ConditionTypeToString(condition->GetType());
		data += " ";
		data += condition->GetValue();

		--_depth;
	}

	std::string ScriptsDocument::GetTabsByDepth() const
	{
		std::string tabs;
		for (int i = 0; i < _depth; ++i)
		{
			tabs += "\t";
		}
		return tabs;
	}
}
