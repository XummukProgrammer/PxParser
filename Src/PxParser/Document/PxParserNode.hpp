#ifndef _PX_PARSER_NODE_HEADER_
#define _PX_PARSER_NODE_HEADER_

#include <PxParser/Document/PxParserValue.hpp>
#include <PxParser/Document/PxParserCondition.hpp>

#include <vector>
#include <memory>
#include <string>

namespace PxParser
{
	class Node final
	{
	public:
		using ChildPtr = std::shared_ptr<Node>;
		using Children = std::vector<ChildPtr>;
		using ChildrenConstIterator = Children::const_iterator;

		using ValuePtr = std::shared_ptr<Value>;
		using Values = std::vector<ValuePtr>;
		using ValuesConstIterator = Values::const_iterator;

		using ConditionPtr = std::shared_ptr<Condition>;
		using Conditions = std::vector<ConditionPtr>;
		using ConditionsConstIterator = Conditions::const_iterator;

	public:
		Node(const std::string& name);
		~Node() = default;

	public:
		const std::string& GetName() const;

	public:
		const Children& GetChildren() const;
		ChildrenConstIterator GetChildrenBegin() const;
		ChildrenConstIterator GetChildrenEnd() const;

	public:
		const Values& GetValues() const;
		ValuesConstIterator GetValuesBegin() const;
		ValuesConstIterator GetValuesEnd() const;

	public:
		const Conditions& GetConditions() const;
		ConditionsConstIterator GetConditionsBegin() const;
		ConditionsConstIterator GetConditionsEnd() const;

	public:
		ChildPtr CreateChild(const std::string& name);
		ValuePtr CreateValue(const std::string& name);
		ConditionPtr CreateCondition(const std::string& name);

	public:
		ChildPtr GetOrCreateChild(const std::string& name);
		ValuePtr GetOrCreateValue(const std::string& name);
		ConditionPtr GetOrCreateCondition(const std::string& name);

	private:
		void AddChild(const ChildPtr& child);
		std::vector<ChildPtr> GetChild(const std::string& name) const;

	private:
		void AddValue(const ValuePtr& value);
		std::vector<ValuePtr> GetValue(const std::string& name) const;

	private:
		void AddCondition(const ConditionPtr& condition);
		std::vector<ConditionPtr> GetCondition(const std::string& name) const;

	private:
		std::string _name;
		Children _children;
		Values _values;
		Conditions _conditions;
	};
}

#endif // _PX_PARSER_NODE_HEADER_
