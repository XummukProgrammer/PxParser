#include "PxParserValue.hpp"

#include <PxParser/Document/PxParserDocument.hpp>

namespace PxParser
{
    Value::Value(const std::string& name, const Data::String& value)
        : _name(name)
        , _value(value)
    {
    }

    const std::string& Value::GetName() const
    {
        return _name;
    }

    const Data::String& Value::GetValue() const
    {
        return _value;
    }
}
