#include "Lexer.hpp"

Lexer::Lexer(void) : lineNumber(0), internalMessage(LexerMessage::noError)
{
	lineFromFile.reserve(bufferSize);
}


Lexer::Lexer(std::string& filename) : Lexer()
{
	readFile.open(filename);
}


Lexer::~Lexer(void) {}


void Lexer::getFilename(std::string& filename)
{
	readFile.open(filename);

	if (!readFile.is_open())
		internalMessage = LexerMessage::badFile;
}


Lexer::Instruction Lexer::getInstruction(void)
{
	return instruction;
}


void Lexer::readLine(void)
{
	if (!readFile.is_open())
	{
		internalMessage = LexerMessage::badFile;
		return;
	}

	for(; !readFile.eof(); ++lineNumber)
	{
		readFile.getline(&lineFromFile[0], bufferSize);

		if (lineFromFile[0] != ';')
			break;
	}

	if (readFile.eof())
		internalMessage = LexerMessage::eof;
}


void Lexer::parse(void)
{

}


LexerMessage Lexer::tokenize(void)
{
	readLine();

	if (internalMessage != LexerMessage::noError)
		return internalMessage;

	std::string::iterator iterator;
	for (auto it = lineFromFile.begin(); it != lineFromFile.end(); ++it)
	{
		iterator = std::find(it, lineFromFile.end(), '\n');

		if (iterator == lineFromFile.end())
			break;
		
		tokens.push_back("");
		std::copy(lineFromFile.begin(), iterator, tokens.end());
	}

	parse();

	if (internalMessage != LexerMessage::noError)
		return internalMessage;
}