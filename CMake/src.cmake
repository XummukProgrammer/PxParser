
set(PX_HEADERS
	src/PxParser/PxParser.hpp
	
	src/PxParser/Lexer/PxParserLexer.hpp
	src/PxParser/Lexer/PxParserToken.hpp
	
	src/PxParser/Document/PxParserDocument.hpp
	src/PxParser/Document/PxParserScriptsDocument.hpp
	src/PxParser/Document/PxParserLocalizationDocument.hpp
	src/PxParser/Document/PxParserNode.hpp
	src/PxParser/Document/PxParserValue.hpp
	src/PxParser/Document/PxParserCondition.hpp
	
	src/PxParser/Helpers/PxParserConverters.hpp
	src/PxParser/Helpers/PxParserDebugPrinters.hpp
	src/PxParser/Helpers/PxParserFilesHelper.hpp
	src/PxParser/Helpers/PxParserStringHelper.hpp
	
	src/PxParser/Data/PxParserString.hpp
	
	src/PxParser/FileSystem/PxParserFileSystem.hpp
	src/PxParser/FileSystem/PxParserModFile.hpp
	src/PxParser/FileSystem/PxParserMod.hpp
	src/PxParser/FileSystem/PxParserLocalizations.hpp
)

set(PX_SOURCES
	src/PxParser/main.cpp
	
	src/PxParser/PxParser.cpp
	
	src/PxParser/Lexer/PxParserLexer.cpp
	src/PxParser/Lexer/PxParserToken.cpp
	
	src/PxParser/Document/PxParserDocument.cpp
	src/PxParser/Document/PxParserScriptsDocument.cpp
	src/PxParser/Document/PxParserLocalizationDocument.cpp
	src/PxParser/Document/PxParserNode.cpp
	src/PxParser/Document/PxParserValue.cpp
	src/PxParser/Document/PxParserCondition.cpp
	
	src/PxParser/Helpers/PxParserConverters.cpp
	src/PxParser/Helpers/PxParserDebugPrinters.cpp
	src/PxParser/Helpers/PxParserFilesHelper.cpp
	src/PxParser/Helpers/PxParserStringHelper.cpp
	
	src/PxParser/Data/PxParserString.cpp
	
	src/PxParser/FileSystem/PxParserFileSystem.cpp
	src/PxParser/FileSystem/PxParserModFile.cpp
	src/PxParser/FileSystem/PxParserMod.cpp
	src/PxParser/FileSystem/PxParserLocalizations.cpp
)
