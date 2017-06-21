#include "Token.h"
#include "Tree.h"
#include "LexicalAnalyzer.h"
#include "SintacticAnalizer.h"
#include <vector>

using namespace std;

void printListOfTokens(vector<Token*> *l){
    for (unsigned int i=0; i<l->size(); ++i)
        cout << "token "<< l->at(i)->token<<" " << " lexeme: " << l->at(i)->value<<'\t'<< l->at(i)->line<< endl;
}

void printLexicalErrors(vector<Token*> *l){
    for (unsigned int i=0; i<l->size(); ++i)
        if (l->at(i)->token == TypeToken::invalido)
            cout<< "error lexico en la linea "<< l->at(i)->line << " : " <<l->at(i)->value <<endl;
}

void eraseListOfTokens(vector<Token*> *l){
    for (unsigned int i=0; i<l->size(); ++i)
        delete l->back();
    l->clear();
}

int main()
{
    vector<Token*> listOfTokens;
	LexicalAnalyzer la;

    la.analyze((char*)"Text.txt", &listOfTokens);
    //printListOfTokens(&listOfTokens);
    cout<<endl;

    if (la.errors == 0){
        Tree myTree;
        SintacticAnalizer sa;

        sa.analiyze(&listOfTokens, &myTree);
        myTree.printTree();
    }else{
        cout << "ERRORES LEXICOS " <<endl;
        printLexicalErrors(&listOfTokens);
    }
    eraseListOfTokens(&listOfTokens);
	return 1;
}

