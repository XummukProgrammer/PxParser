#ifndef _PX_PARSER_MOD_HEADER_
#define _PX_PARSER_MOD_HEADER_

#include <PxParser/FileSystem/PxParserLocalizations.hpp>

#include <string>

namespace PxParser
{
	class Mod final
	{
	public:
		Mod(const std::string& name, const std::string& path);
		~Mod() = default;

	public:
		std::string GetLocalizationsFolderPath() const;

	public:
		const std::string& GetName() const;
		const std::string& GetPath() const;
		const Localizations& GetLocalizations() const;

	public:
		void Update();

	private:
		std::string _name;
		std::string _path;
		Localizations _localizations;
	};
}

#endif // _PX_PARSER_MOD_HEADER_
