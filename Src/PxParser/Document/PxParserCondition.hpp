#ifndef _PX_PARSER_CONDITION_HEADER_
#define _PX_PARSER_CONDITION_HEADER_

#include <string>

namespace PxParser
{
	class Condition final
	{
	public:
		enum class Type
		{
			More,
			Less
		};

	public:
		Condition(const std::string& name, Type type, const std::string& value);
		~Condition() = default;

	public:
		const std::string& GetName() const;
		Type GetType() const;
		const std::string& GetValue() const;

	private:
		std::string _name;
		Type _type;
		std::string _value;
	};
}

#endif // _PX_PARSER_CONDITION_HEADER_
