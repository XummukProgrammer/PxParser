﻿#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::Document doc;
	doc.LoadFromFile("D:\\Git\\PxParser\\Assets\\test.txt");
	system("pause");
	return 0;
}
