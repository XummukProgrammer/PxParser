﻿#include <PxParser/PxParser.hpp>

int main(int argc, char** argv)
{
	PxParser::LocalizationDocument document;
	document.LoadFromFile("D:\\Git\\PxParser\\Assets\\test.txt");
	document.SaveToFile("D:\\Git\\PxParser\\Assets\\out.txt");

	system("pause");
	return 0;
}
