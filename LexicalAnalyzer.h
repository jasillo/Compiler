#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <vector>
#include "Token.h"

using namespace std;

class LexicalAnalyzer
{
private:
	string lexeme;
	unsigned int line;
	void saveLexeme(TypeToken code);
	vector<Token*> myTokens;
	bool isMonoLexeme(char c, TypeToken t);
	bool isBiLexeme(char c, TypeToken t);
	int state;
	vector<string> nameTokens;

public:
	LexicalAnalyzer();
	~LexicalAnalyzer();
	void printAll();

	bool analyze(char* name);
};

