#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::Lexer lexer;
	lexer.LoadFromFile("D:\\Git\\PxParser\\Assets\\test.txt");
	lexer.DebugPrintTokens();
	system("pause");
	return 0;
}
