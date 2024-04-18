#ifndef _PX_PARSER_VALUE_HEADER_
#define _PX_PARSER_VALUE_HEADER_

#include <string>

namespace PxParser
{
	class Value final
	{
	public:
		Value(const std::string& name, const std::string& value);
		~Value() = default;

	public:
		const std::string& GetName() const;
		const std::string& GetValue() const;

	private:
		std::string _name;
		std::string _value;
	};
}

#endif // _PX_PARSER_VALUE_HEADER_
