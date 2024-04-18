#include "PxParserValue.hpp"

namespace PxParser
{
    Value::Value(const std::string& name, const std::string& value)
        : _name(name)
        , _value(value)
    {
    }

    const std::string& Value::GetName() const
    {
        return _name;
    }

    const std::string& Value::GetValue() const
    {
        return _value;
    }
}
