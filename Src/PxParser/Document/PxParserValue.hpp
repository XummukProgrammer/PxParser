#ifndef _PX_PARSER_VALUE_HEADER_
#define _PX_PARSER_VALUE_HEADER_

#include <PxParser/Data/PxParserString.hpp>

namespace PxParser
{
	class Value final
	{
	public:
		Value(const std::string& name, const Data::String& value);
		~Value() = default;

	public:
		const std::string& GetName() const;
		const Data::String& GetValue() const;

	public:
		void SetValue(const std::string& value, bool isStrong = false);
		void SetValue(const Data::String& string);

	private:
		std::string _name;
		Data::String _value;
	};
}

#endif // _PX_PARSER_VALUE_HEADER_
