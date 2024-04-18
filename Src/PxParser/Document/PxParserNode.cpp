#include "PxParserNode.hpp"

namespace PxParser
{
    Node::Node(const std::string& name)
        : _name(name)
    {
    }

    const std::string& Node::GetName() const
    {
        return _name;
    }

    void Node::AddChild(const ChildPtr& child)
    {
        _children.push_back(child);
    }

    Node::ChildPtr Node::GetChild(const std::string& name) const
    {
        for (const auto& child : _children)
        {
            if (child->GetName() == name)
            {
                return child;
            }
        }
        return nullptr;
    }

    const Node::Children& Node::GetChildren() const
    {
        return _children;
    }

    Node::ChildrenConstIterator Node::GetChildrenBegin() const
    {
        return _children.begin();
    }

    Node::ChildrenConstIterator Node::GetChildrenEnd() const
    {
        return _children.end();
    }

    void Node::AddValue(const ValuePtr& value)
    {
        _values.push_back(value);
    }

    Node::ValuePtr Node::GetValue(const std::string& name) const
    {
        for (const auto& value : _values)
        {
            if (value->GetName() == name)
            {
                return value;
            }
        }
        return nullptr;
    }

    const Node::Values& Node::GetValues() const
    {
        return _values;
    }

    Node::ValuesConstIterator Node::GetValuesBegin() const
    {
        return _values.begin();
    }

    Node::ValuesConstIterator Node::GetValuesEnd() const
    {
        return _values.end();
    }

    void Node::AddCondition(const ConditionPtr& condition)
    {
        _conditions.push_back(condition);
    }

    Node::ConditionPtr Node::GetCondition(const std::string& name) const
    {
        for (const auto& condition : _conditions)
        {
            if (condition->GetName() == name)
            {
                return condition;
            }
        }
        return nullptr;
    }

    const Node::Conditions& Node::GetConditions() const
    {
        return _conditions;
    }

    Node::ConditionsConstIterator Node::GetConditionsBegin() const
    {
        return _conditions.begin();
    }

    Node::ConditionsConstIterator Node::GetConditionsEnd() const
    {
        return _conditions.end();
    }
}
