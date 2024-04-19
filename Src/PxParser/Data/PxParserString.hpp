#ifndef _PX_PARSER_STRING_HEADER_
#define _PX_PARSER_STRING_HEADER_

#include <string>

namespace PxParser::Data
{
	class String final
	{
	public:
		String();
		String(const std::string& string);
		String(const std::string& string, bool isStrong);
		String(const String& string);
		String(String&& string) noexcept;
		~String() = default;

	public:
		const std::string& GetString() const;
		bool IsStrong() const;

	public:
		operator std::string() const;

	public:
		String& operator=(const String& string);
		String& operator=(String&& string) noexcept;

		bool operator==(const String& string) const;
		bool operator==(const char* string) const;

		bool operator!=(const String& string) const;
		bool operator!=(const char* string) const;

	public:
		void Save(std::string& data) const;

	private:
		std::string _string;
		bool _isStrong;
	};
}

#endif // _PX_PARSER_STRING_HEADER_
