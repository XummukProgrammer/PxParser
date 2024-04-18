#ifndef _PX_PARSER_TOKEN_HEADER_
#define _PX_PARSER_TOKEN_HEADER_

#include <string>

namespace PxParser
{
	class Token final
	{
	public:
		enum class Type
		{
			Operator,
			Number,
			String
		};

	public:
		Token(const std::string& text, Type type);
		~Token() = default;
		
	public:
		const std::string& GetText() const;
		Type GetType() const;

	private:
		std::string _text;
		Type _type;
	};
}

#endif // _PX_PARSER_TOKEN_HEADER_
