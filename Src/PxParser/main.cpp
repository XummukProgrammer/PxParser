#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::ScriptsDocument doc;
	doc.LoadFromFile("D:\\Git\\PxParser\\Assets\\test.txt");
	doc.SaveToFile("D:\\Git\\PxParser\\Assets\\out.txt");
	system("pause");
	return 0;
}
