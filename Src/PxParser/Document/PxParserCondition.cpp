#include "PxParserCondition.hpp"

#include <PxParser/Document/PxParserDocument.hpp>

namespace PxParser
{
    Condition::Condition(const std::string& name, Type type, const std::string& value)
        : _name(name)
        , _type(type)
        , _value(value)
    {
    }

    const std::string& Condition::GetName() const
    {
        return _name;
    }

    Condition::Type Condition::GetType() const
    {
        return _type;
    }

    const std::string& Condition::GetValue() const
    {
        return _value;
    }

    void Condition::Save(std::string& data, int& depth)
    {
        data += "\n";
        data += Document::GetTabsByDepth(depth);
        data += _name;
        data += " " + TypeToString(_type) + " ";
        data += _value;
    }

    std::string Condition::TypeToString(Type type)
    {
        switch (type)
        {
        case Type::More:
            return ">";

        case Type::Less:
            return "<";
        }
        return "!!!UNKNOWN!!!";
    }
}
