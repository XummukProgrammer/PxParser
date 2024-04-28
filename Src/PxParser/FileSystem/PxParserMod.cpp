#include "PxParserMod.hpp"

namespace PxParser
{
	Mod::Mod(const std::string& name, const std::string& path)
		: _name(name)
		, _path(path)
	{
	}

	std::string Mod::GetLocalizationsFolderPath() const
	{
		return _path + "/localisation/";
	}

	const std::string& Mod::GetName() const
	{
		return _name;
	}

	const std::string& Mod::GetPath() const
	{
		return _path;
	}

	const Localizations& Mod::GetLocalizations() const
	{
		return _localizations;
	}

	void Mod::Update()
	{
		//_localizations.Update(GetLocalizationsFolderPath());
	}
}
