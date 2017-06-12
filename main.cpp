#include "LexicalAnalyzer.h"

using namespace std;

int main()
{
    char a = ' ';
	LexicalAnalyzer la;
    la.analyze("Text.txt");
    la.printAll();
	return 1;
}
