#ifndef _PX_PARSER_TOKEN_HEADER_
#define _PX_PARSER_TOKEN_HEADER_

#include <PxParser/Data/PxParserString.hpp>

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
		Token(const std::string& text, bool isStrong, Type type);
		~Token() = default;
		
	public:
		const Data::String& GetText() const;
		Type GetType() const;

	private:
		Data::String _text;
		Type _type;
	};
}

#endif // _PX_PARSER_TOKEN_HEADER_
