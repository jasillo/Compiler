#include "LexicalAnalyzer.h"



void LexicalAnalyzer::saveLexeme(TypeToken code)
{
    Token *t = new struct Token;
    t->token = code;
    t->value = lexeme;
    myTokens.push_back(t);
	//cout << "code: " << code << " lexeme: " << lexeme << endl;
}

LexicalAnalyzer::LexicalAnalyzer()
{
	lexeme = "";
}


LexicalAnalyzer::~LexicalAnalyzer()
{
}

bool LexicalAnalyzer::analyze(char* name)
{
	ifstream fs(name, ifstream::in);
	if (fs.fail())
		return false;
	char c;
	state = 0;

	bool isBreaker = false;
	while (!fs.eof())
	{
		if (!isBreaker)
			c = fs.get();

		switch (state){
		case 0: //lexeme esta vacio
		    isBreaker = false;
		    lexeme = c;
		    if (isMonoLexeme(c, TypeToken::vaci)){
                lexeme = "";
		    }else if (isBiLexeme(c, TypeToken::vaci)){
                //
		    }else if (isalpha(c)){
                state = 20;
		    }else if (isdigit(c)){
                state = 30;
            }else if (c == '"'){
                state = 40;
                lexeme = "";
            }else if (c == ' ' || c == '\n')
                lexeme = "";

			break;
		case 1: // inicio comentaio o division
			if (c == '*'){ //comentario /*
                state = 2;
                lexeme = "";
			} else if (c == '/'){ //comentatio //
                state = 4;
                lexeme = "";
            }else{
                saveLexeme(TypeToken::divi);
                isBreaker = true;
                state = 0;
            }
			break;
		case 2: //comentarios
			if (c == '*') state = 3;
			break;
        case 3: //comentarios
            if (c == '*') break;
			if (c == '/') state = 0;
            else          state = 2;
			break;
		case 4: //comentarios
			if (c == '\n')
                state = 0;
			break;
        case 10:
            if (c == '='){
                lexeme += c;
            }else
                isBreaker = true;
            saveLexeme(TypeToken::comp);
            state = 0;
			break;
		case 11:
            if (c == '='){
                lexeme += c;
                saveLexeme(TypeToken::comp);
            }else{
                isBreaker = true;
                saveLexeme(TypeToken::asig);
            }
            state = 0;
			break;
        case 12:
            if (c == '='){
                lexeme += c;
                saveLexeme(TypeToken::comp);
            }else{
                isBreaker = true;
                saveLexeme(TypeToken::nega);
            }
            state = 0;
			break;
        case 20: // identificadores y palabras reservada
            if (isxdigit(c) || c == '_')
                lexeme += c;
            else if (c == '\n' || c == ' '){
                saveLexeme(TypeToken::iden);
                state = 0;
            }else{
                if (isMonoLexeme(c, TypeToken::iden)){
                    state = 0;
                } else if (isBiLexeme(c, TypeToken::iden)){
                    //
                }else{
                    state = 99;
                    lexeme += c;
                }
            }
            break;

        case 30://digitos
            if (isdigit(c)){
                lexeme += c;
            }else if (c == '.'){
                lexeme += c;
                state = 31;
            }else{
                if (isMonoLexeme(c, TypeToken::digi)){
                    state = 0;
                } else if (isBiLexeme(c, TypeToken::digi)){
                    //
                } else if(c == '\n' || c == ' '){
                    saveLexeme(TypeToken::digi);
                    state = 0;
                }else{
                    state = 99;
                    lexeme += c;
                }
            }
            break;
        case 31: //por lo menos un digito
            if (isdigit(c)){
                lexeme += c;
                state = 32;
            } else if (c == '\n' || c == ' ' ){
                saveLexeme(TypeToken::inva);
                state = 0;
            } else{
                state = 99;
                lexeme += c;
            }
            break;
        case 32:
            if (isdigit(c)){
                lexeme += c;
            }else{
                if (isMonoLexeme(c, TypeToken::digi)){
                    state = 0;
                } else if (isBiLexeme(c, TypeToken::digi)){
                    //
                } else if (c == '\n' || c == ' '){
                    saveLexeme(TypeToken::digi);
                    state = 0;
                }else{
                    state = 99;
                    lexeme += c;
                }
            }
		case 40: // es una cadena
		    if (c == '"'){
                saveLexeme(TypeToken::cade);
                state = 0;
		    } else if (c == '\n'){
		        saveLexeme(TypeToken::inva);
		        state = 0;
		    } else
                lexeme += c;
            break;
        case 99: //dato invalido
            if (isMonoLexeme(c, TypeToken::inva)){
                state = 0;
            } else if (isBiLexeme(c, TypeToken::inva)){
                //
            } else if (c == '\n' || c == ' '){
                saveLexeme(TypeToken::inva);
                state = 0;
            } else{
                lexeme += c;
            }
            break;
		default:
			break;
		}

	}
	fs.close();
}

bool LexicalAnalyzer::isMonoLexeme(char c, TypeToken t)
{
    TypeToken temp = TypeToken::inva;
    if (c == '+')
        temp = TypeToken::suma;
    else if (c == '-')
        temp = TypeToken::rest;
    else if (c == '*')
        temp = TypeToken::mult;
    else if (c == '%')
        temp = TypeToken::modu;
    else if (c == '(')
        temp = TypeToken::pari;
    else if (c == ')')
        temp = TypeToken::pard;
    else if (c == '{')
        temp = TypeToken::llai;
    else if (c == '}')
        temp = TypeToken::llad;
    else if (c == '[')
        temp = TypeToken::pari;
    else if (c == ']')
        temp = TypeToken::pari;
    else if (c == ',')
        temp = TypeToken::sepa;
    else if (c == ';')
        temp = TypeToken::fini;
    else if (c == '?')
        temp = TypeToken::opet;
    else if (c == '.')
        temp = TypeToken::punt;
    else
        return false;

    if (t != TypeToken::vaci)
        saveLexeme(t);
    lexeme = c;
    saveLexeme(temp);
    return true;
}

bool LexicalAnalyzer::isBiLexeme(char c, TypeToken t){

    if (c == '/'){
        state = 1;
    }else if (c == '<'){
        state = 10;
    }else if (c == '>'){
        state = 10;
    }else if (c == '='){
        state = 11;
    }else if (c == '!'){
        state = 12;
    }else
        return false;
    if (t != TypeToken::vaci)
        saveLexeme(t);
    lexeme = c;
    return true;
}
void LexicalAnalyzer::printAll(){
    for (int i=0; i<myTokens.size(); ++i)
        cout << "token: " << myTokens[i]->token << " lexeme: " << myTokens[i]->value << endl;
}
