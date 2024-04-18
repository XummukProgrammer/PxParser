#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::Document doc;
	doc.LoadFromFile("D:\\Git\\PxParser\\Assets\\test.txt");

	const auto& arr = doc.GetRoot()->GetChild("tags")[0]->GetArray();

	system("pause");
	return 0;
}
