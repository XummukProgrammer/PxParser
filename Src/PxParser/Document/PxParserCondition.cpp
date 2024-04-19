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

    void Condition::SetType(Type type)
    {
        _type = type;
    }

    void Condition::SetValue(const std::string& value)
    {
        _value = value;
    }
}
