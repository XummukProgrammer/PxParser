#include "PxParserValue.hpp"

#include <PxParser/Document/PxParserDocument.hpp>

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

    void Value::Save(std::string& data, int& depth)
    {
        const auto& tabs = Document::GetTabsByDepth(depth);

        if (_name != "Array")
        {
            data += "\n";
            data += tabs;
            data += _name;
            data += " = ";
        }
        else
        {
            data += tabs;
        }
        
        data += _value;
    }
}
