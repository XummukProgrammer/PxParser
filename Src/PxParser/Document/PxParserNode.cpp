﻿#include "PxParserNode.hpp"

#include <PxParser/Document/PxParserDocument.hpp>

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

    std::vector<Node::ChildPtr> Node::GetChild(const std::string& name) const
    {
        std::vector<Node::ChildPtr> children;
        for (const auto& child : _children)
        {
            if (child->GetName() == name)
            {
                children.push_back(child);
            }
        }
        return children;
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

    std::vector<Node::ValuePtr> Node::GetValue(const std::string& name) const
    {
        std::vector<ValuePtr> values;
        for (const auto& value : _values)
        {
            if (value->GetName() == name)
            {
                values.push_back(value);
            }
        }
        return values;
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

    std::vector<Node::ConditionPtr> Node::GetCondition(const std::string& name) const
    {
        std::vector<Node::ConditionPtr> conditions;
        for (const auto& condition : _conditions)
        {
            if (condition->GetName() == name)
            {
                conditions.push_back(condition);
            }
        }
        return conditions;
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

    Node::ChildPtr Node::CreateChild(const std::string& name)
    {
        auto newChild = std::make_shared<Node>(name);
        AddChild(newChild);
        return newChild;
    }

    Node::ValuePtr Node::CreateValue(const std::string& name)
    {
        auto newValue = std::make_shared<Value>(name, Data::String());
        AddValue(newValue);
        return newValue;
    }

    Node::ConditionPtr Node::CreateCondition(const std::string& name)
    {
        auto newCondition = std::make_shared<Condition>(name, Condition::Type::Less, "0");
        AddCondition(newCondition);
        return newCondition;
    }

    Node::ChildPtr Node::GetOrCreateChild(const std::string& name)
    {
        auto children = GetChild(name);
        if (children.size() > 0)
        {
            return children[0];
        }
        return CreateChild(name);
    }

    Node::ValuePtr Node::GetOrCreateValue(const std::string& name)
    {
        auto values = GetValue(name);
        if (values.size() > 0)
        {
            return values[0];
        }
        return CreateValue(name);
    }

    Node::ConditionPtr Node::GetOrCreateCondition(const std::string& name)
    {
        auto conditions = GetCondition(name);
        if (conditions.size() > 0)
        {
            return conditions[0];
        }
        return CreateCondition(name);
    }
}
