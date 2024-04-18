
set(PX_HEADERS
	src/PxParser/PxParser.hpp
	
	src/PxParser/Lexer/PxParserLexer.hpp
	src/PxParser/Lexer/PxParserToken.hpp
	
	src/PxParser/Document/PxParserDocument.hpp
	src/PxParser/Document/PxParserNode.hpp
	src/PxParser/Document/PxParserValue.hpp
	src/PxParser/Document/PxParserCondition.hpp
)

set(PX_SOURCES
	src/PxParser/main.cpp
	
	src/PxParser/PxParser.cpp
	
	src/PxParser/Lexer/PxParserLexer.cpp
	src/PxParser/Lexer/PxParserToken.cpp
	
	src/PxParser/Document/PxParserDocument.cpp
	src/PxParser/Document/PxParserNode.cpp
	src/PxParser/Document/PxParserValue.cpp
	src/PxParser/Document/PxParserCondition.cpp
)
