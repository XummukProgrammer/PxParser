#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::FileSystem fileSystem("C:\\Documents\\Paradox Interactive\\Hearts of Iron IV");
	fileSystem.Update();

	const auto& modFile = fileSystem.GetModFileByName("Equestria at War");
	if (modFile != nullptr)
	{
		PxParser::Mod mod(modFile->GetName(), modFile->GetPath());
		mod.Update();
	}

	system("pause");
	return 0;
}
