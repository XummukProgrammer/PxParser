#ifndef _PX_PARSER_LOCALIZATIONS_HEADER_
#define _PX_PARSER_LOCALIZATIONS_HEADER_

#include <string>
#include <map>

namespace PxParser
{
	class Localizations final
	{
	public:
		Localizations() = default;
		~Localizations() = default;

	public:
		void Update(const std::string& path);

	public:
		std::string GetTransition(const std::string& localeName, const std::string& transitionName) const;

	private:
		std::string _path;
		std::map<std::string, std::map<std::string, std::string>> _localizations; // [LocaleName][TransitionName]
	};
}

#endif // _PX_PARSER_LOCALIZATIONS_HEADER_
