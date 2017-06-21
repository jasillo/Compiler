#ifndef SINTACTICANALIZER_H
#define SINTACTICANALIZER_H
#include <vector>
#include "Token.h"
#include "Tree.h"

#define ROWS 25
#define COLUMNS 29

using namespace std;

class SintacticAnalizer
{
    public:
        SintacticAnalizer();
        virtual ~SintacticAnalizer();

        bool analiyze(vector<Token*> *l, Tree *t);
    private:
        void reverseVector(vector<Token*> *l);
        vector<TypeToken> syntacticStack;
        vector<TypeToken>* getProduction(struct Token *t, TypeToken c);
        vector<TypeToken> syntacticTable[ROWS][COLUMNS];


};

#endif // SINTACTICANALIZER_H
