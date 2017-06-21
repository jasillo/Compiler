#include "SintacticAnalizer.h"

SintacticAnalizer::SintacticAnalizer()
{
    //añadiendo gramatica a la tabla sintactica
    syntacticTable[0][0].push_back(TypeToken::vacio);
    syntacticTable[0][1] = vector<TypeToken>{tVoid,id,parIzq,P,parDer,F,S};
    syntacticTable[0][2] = vector<TypeToken>{tipodato,id,S_,S};

    syntacticTable[1][0].push_back(TypeToken::vacio);
    syntacticTable[1][1].push_back(TypeToken::vacio);
    syntacticTable[1][2].push_back(TypeToken::vacio);
    syntacticTable[1][3] = vector<TypeToken>{parIzq,P,parDer,F};
    syntacticTable[1][5] = vector<TypeToken>{Ar,Ld,finInst};
    syntacticTable[1][7] = syntacticTable[1][5];
    syntacticTable[1][10].push_back(finInst);

    syntacticTable[2][5] = vector<TypeToken>{corIzq,Ar_};
    syntacticTable[2][7].push_back(TypeToken::Ar__);
    syntacticTable[2][9].push_back(TypeToken::vacio);
    syntacticTable[2][10].push_back(TypeToken::vacio);

    syntacticTable[3][6] = vector<TypeToken>{corDer,igual,llaIzq,Le,llaDer};
    syntacticTable[3][11] = vector<TypeToken>{id,corDer};
    syntacticTable[3][18] = vector<TypeToken>{digEnt,corDer};

    syntacticTable[4][7] = vector<TypeToken>{igual,E,Ar___};
    syntacticTable[4][9].push_back(TypeToken::vacio);
    syntacticTable[4][10].push_back(TypeToken::vacio);

    syntacticTable[5][8] = vector<TypeToken>{igualoper,E,Ar___};
    syntacticTable[5][9].push_back(TypeToken::vacio);
    syntacticTable[5][10].push_back(TypeToken::vacio);

    syntacticTable[6][9] = vector<TypeToken>{coma,id,Ar,Ld};
    syntacticTable[6][10].push_back(TypeToken::vacio);

    syntacticTable[7][2] = vector<TypeToken>{tipodato,id,Ar,Ld};
    syntacticTable[7][4].push_back(TypeToken::vacio);

    syntacticTable[8][4].push_back(TypeToken::vacio);
    syntacticTable[8][9] = vector<TypeToken>{coma,tipodato,id,Ar,P_};

    syntacticTable[9][10].push_back(TypeToken::finInst);
    syntacticTable[9][12] = vector<TypeToken>{llaIzq,Li,llaDer};

    syntacticTable[10][2] = vector<TypeToken>{tipodato,id,Ar,Ld,finInst,Li};
    syntacticTable[10][10] = vector<TypeToken>{finInst,Li};
    syntacticTable[10][11] = vector<TypeToken>{id,I,finInst,Li};
    syntacticTable[10][13].push_back(TypeToken::vacio);
    syntacticTable[10][14] = vector<TypeToken>{palIf,parIzq,E,parDer,B,B_,Li};
    syntacticTable[10][15] = vector<TypeToken>{palWhile,parIzq,E,parDer,B,Li};
    syntacticTable[10][16] = vector<TypeToken>{palBreak,finInst,Li};
    syntacticTable[10][28] = vector<TypeToken>{palReturn,E,finInst,Li};

    syntacticTable[11][3] = vector<TypeToken>{parIzq,Le,parDer};
    syntacticTable[11][5] = vector<TypeToken>{corIzq,digEnt,corDer,Ar___};
    syntacticTable[11][7] = vector<TypeToken>{igual,E,Ar___};

    syntacticTable[12][2] = vector<TypeToken>{tipodato,id,Ar,Ld,finInst};
    syntacticTable[12][10].push_back(finInst);
    syntacticTable[12][11] = vector<TypeToken>{id,I,finInst};
    syntacticTable[12][12] = vector<TypeToken>{llaIzq,Li,llaDer};
    syntacticTable[12][14] = vector<TypeToken>{palIf,parIzq,E,parDer,B};
    syntacticTable[12][15] = vector<TypeToken>{palWhile,parIzq,E,parDer,B};
    syntacticTable[12][16] = vector<TypeToken>{palBreak,finInst};
    syntacticTable[12][28] = vector<TypeToken>{palReturn,E,finInst};

    syntacticTable[13][2].push_back(vacio);
    syntacticTable[13][10].push_back(vacio);
    syntacticTable[13][11].push_back(vacio);
    syntacticTable[13][13].push_back(vacio);
    syntacticTable[13][14].push_back(vacio);
    syntacticTable[13][15].push_back(vacio);
    syntacticTable[13][16].push_back(vacio);
    syntacticTable[13][17] = vector<TypeToken>{palElse,B};

    syntacticTable[14][2] = vector<TypeToken>{E,Le_};
    syntacticTable[14][3] = vector<TypeToken>{E,Le_};
    syntacticTable[14][4].push_back(vacio);
    syntacticTable[14][11] = vector<TypeToken>{E,Le_};
    syntacticTable[14][13].push_back(vacio);
    syntacticTable[14][18] = vector<TypeToken>{E,Le_};
    syntacticTable[14][19] = vector<TypeToken>{E,Le_};
    syntacticTable[14][20] = vector<TypeToken>{E,Le_};
    syntacticTable[14][21] = vector<TypeToken>{E,Le_};
    syntacticTable[14][27] = vector<TypeToken>{E,Le_};

    syntacticTable[15][4].push_back(vacio);
    syntacticTable[15][9] = vector<TypeToken>{coma,E,Le_};
    syntacticTable[15][13].push_back(vacio);

    syntacticTable[16][2] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][3] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][11] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][18] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][19] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][20] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][21] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][24] = vector<TypeToken>{Si,M,Mo,Su,Co,L};
    syntacticTable[16][27] = vector<TypeToken>{Si,M,Mo,Su,Co,L};

    syntacticTable[17][4].push_back(vacio);
    syntacticTable[17][7].push_back(vacio);
    syntacticTable[17][9].push_back(vacio);
    syntacticTable[17][10].push_back(vacio);
    syntacticTable[17][22] = vector<TypeToken>{logico,Si,M,Mo,Su,Co,L};

    syntacticTable[18][4].push_back(vacio);
    syntacticTable[18][7].push_back(vacio);
    syntacticTable[18][9].push_back(vacio);
    syntacticTable[18][10].push_back(vacio);
    syntacticTable[18][22].push_back(vacio);
    syntacticTable[18][23] = vector<TypeToken>{comp,Si,M,Mo,Su,Co};

    syntacticTable[19][4].push_back(vacio);
    syntacticTable[19][7].push_back(vacio);
    syntacticTable[19][9].push_back(vacio);
    syntacticTable[19][10].push_back(vacio);
    syntacticTable[19][22].push_back(vacio);
    syntacticTable[19][23].push_back(vacio);
    syntacticTable[19][24] = vector<TypeToken>{suma,Si,M,Mo,Su};

    syntacticTable[20][4].push_back(vacio);
    syntacticTable[20][7].push_back(vacio);
    syntacticTable[20][9].push_back(vacio);
    syntacticTable[20][10].push_back(vacio);
    syntacticTable[20][22].push_back(vacio);
    syntacticTable[20][23].push_back(vacio);
    syntacticTable[20][24].push_back(vacio);
    syntacticTable[20][25] = vector<TypeToken>{modulo,Si,M,Mo};

    syntacticTable[21][4].push_back(vacio);
    syntacticTable[21][7].push_back(vacio);
    syntacticTable[21][9].push_back(vacio);
    syntacticTable[21][10].push_back(vacio);
    syntacticTable[21][22].push_back(vacio);
    syntacticTable[21][23].push_back(vacio);
    syntacticTable[21][24].push_back(vacio);
    syntacticTable[21][25].push_back(vacio);
    syntacticTable[21][26] = vector<TypeToken>{multi,Si,M};

    syntacticTable[22][2].push_back(D);
    syntacticTable[22][3].push_back(D);
    syntacticTable[22][11].push_back(D);
    syntacticTable[22][18].push_back(D);
    syntacticTable[22][19].push_back(D);
    syntacticTable[22][20].push_back(D);
    syntacticTable[22][21].push_back(D);
    syntacticTable[21][24] = vector<TypeToken>{suma,D};
    syntacticTable[22][27].push_back(D);

    syntacticTable[23][2] = vector<TypeToken>{tipodato,parIzq,E,parDer};
    syntacticTable[23][3] = vector<TypeToken>{parIzq,E,parDer};
    syntacticTable[23][11] = vector<TypeToken>{id,D_};
    syntacticTable[23][18] = vector<TypeToken>{digEnt};
    syntacticTable[23][19] = vector<TypeToken>{digReal};
    syntacticTable[23][20] = vector<TypeToken>{booleano};
    syntacticTable[23][21] = vector<TypeToken>{cadena};
    syntacticTable[23][27] = vector<TypeToken>{caracter};

    syntacticTable[24][3] = vector<TypeToken>{parIzq,Le,parDer};
    syntacticTable[24][4].push_back(vacio);
    syntacticTable[24][5] = vector<TypeToken>{corIzq,digEnt,corDer};
    syntacticTable[24][7].push_back(vacio);
    syntacticTable[24][9].push_back(vacio);
    syntacticTable[24][10].push_back(vacio);
    syntacticTable[24][22].push_back(vacio);
    syntacticTable[24][23].push_back(vacio);
    syntacticTable[24][24].push_back(vacio);
    syntacticTable[24][25].push_back(vacio);
    syntacticTable[24][26].push_back(vacio);

    //syntacticTable[0][2].push_back(TypeToken::);
}

SintacticAnalizer::~SintacticAnalizer()
{
    //dtor
}

bool SintacticAnalizer::analiyze(vector<Token*> *lista, Tree *t)
{
    lista->push_back(new struct Token);
    lista->back()->token = TypeToken::vacio;
    lista->back()->value = "$";
    lista->back()->line = 0;
    reverseVector(lista);
    syntacticStack.push_back(vacio);
    syntacticStack.push_back(S);
    t->addRoot(S);
    vector<TypeToken> *produc;
    while (!lista->empty()){
            /*cout<<"sintac : ";
            for (int i = 0; i<syntacticStack.size() ; ++i)
                cout<<syntacticStack.at(i)<<" - ";
            cout<<endl;*/
        if (lista->back()->token == syntacticStack.back()){
            syntacticStack.pop_back();
            lista->pop_back();

        }else{
            produc = getProduction(lista->back(),syntacticStack.back());

            if (produc == nullptr){
                cout<<"error sintactico : "<< lista->back()->token <<endl;
                return false;
            }else if (produc->at(0) == vacio){
                t->addChildren(produc);
                syntacticStack.pop_back();
            }else{
                t->addChildren(produc);
                syntacticStack.pop_back();
                for (int i = produc->size()-1; i>=0 ; --i)
                    syntacticStack.push_back(produc->at(i));
            }
        }
    }
    return true;
}

void SintacticAnalizer::reverseVector(vector<Token*> *l)
{
    int i = 0;
    int j = l->size()-1;
    while (i < j){
        swap (l->at(i),l->at(j));
        ++i;
        --j;
    }
}

vector<TypeToken>* SintacticAnalizer::getProduction(struct Token *t, TypeToken synStack)
{
    int r,c;
    r = synStack - TypeToken::S;
    c = t->token;
    if (syntacticTable[r][c].empty())
        return nullptr;
    return &syntacticTable[r][c];
}

