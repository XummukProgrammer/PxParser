#include "PxParserString.hpp"

namespace PxParser::Data
{
	String::String()
		: String("")
	{
	}

	String::String(const std::string& string)
		: String(string, false)
	{
	}

	String::String(const std::string& string, bool isStrong)
		: _string(string)
		, _isStrong(isStrong)
	{
	}

	String::String(const String& string)
	{
		_string = string._string;
		_isStrong = string._isStrong;
	}

	String::String(String&& string) noexcept
	{
		_string = std::move(string._string);
		_isStrong = string._isStrong;
	}

	const std::string& String::GetString() const
	{
		return _string;
	}

	bool String::IsStrong() const
	{
		return _isStrong;
	}

	void String::Update(const std::string& string, bool isStrong)
	{
		_string = string;
		_isStrong = isStrong;
	}

	String::operator std::string() const
	{
		return _string;
	}

	String& String::operator=(const String& string)
	{
		_string = string._string;
		_isStrong = string._isStrong;
		return *this;
	}

	String& String::operator=(String&& string) noexcept
	{
		_string = std::move(string._string);
		_isStrong = string._isStrong;
		return *this;
	}

	bool String::operator==(const String& string) const
	{
		return _string == string._string;
	}

	bool String::operator==(const char* string) const
	{
		return _string == string;
	}

	bool String::operator!=(const String& string) const
	{
		return _string != string._string;
	}

	bool String::operator!=(const char* string) const
	{
		return _string != string;
	}

	void String::Save(std::string& data) const
	{
		if (_isStrong)
		{
			data += "\"";
		}

		data += _string;
	
		if (_isStrong)
		{
			data += "\"";
		}
	}
}
