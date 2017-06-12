#include "LexicalAnalyzer.h"

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
    line = 1;

	while (!fs.eof())
	{
		if (!isBreaker)
			c = fs.get();

		switch (state){
		case 0: //lexeme esta vacio
		    lexeme = "";
		    isBreaker = false;
		    if (!isMonoLexeme(c, TypeToken::vacio))
                if (!isBiLexeme(c, TypeToken::vacio)){
                    if (isalpha(c)){
                        lexeme = c;
                        state = 20;
                    }else if (isdigit(c)){
                        lexeme = c;
                        state = 30;
                    }else if (c == '"') state = 40;
                    else if (c == '\'') state = 41;
                }
			break;
		case 1: // /
			if (c == '*') state = 2; // /*
            else if (c == '/') state = 4; //comentatio //
            else{
                saveLexeme(TypeToken::divi);
                isBreaker = true;
            }
			break;
		case 2: // /*
			if (c == '*') state = 3; // /* *
			if (c == '\n') ++line;
			break;
        case 3: // /* *
            if (c == '/') state = 0; // /* */
            if (c == '*') break; // /* **
            else  state = 2; // /* [algo mas]
            if (c == '\n') ++line;
			break;
		case 4: // //
			if (c == '\n'){
                state = 0;
                ++line;
			}
			break;
        case 10: // <
            if (c == '=') lexeme += c; // <=
            else isBreaker = true;
            saveLexeme(TypeToken::comp);
			break;
		case 11: // =
            if (c == '='){ // ==
                lexeme += c;
                saveLexeme(TypeToken::comp);
            }else{
                isBreaker = true;
                saveLexeme(TypeToken::igual);
            }
			break;
        case 12: // !
            if (c == '='){ // !=
                lexeme += c;
                saveLexeme(TypeToken::comp);
            }else{
                isBreaker = true;
                saveLexeme(TypeToken::neg);
            }
			break;
        case 13: // >
            if (c == '=') lexeme += c; // >=
            else isBreaker = true;
            saveLexeme(TypeToken::comp);
            break;
        case 20: // identificadores y palabras reservada
            if (!isMonoLexeme(c, TypeToken::id))
                if (!isBiLexeme(c, TypeToken::id)){
                    if (isdigit(c) || isalpha(c) || c == '_')
                        lexeme += c;
                    else{
                        state = 99;
                        lexeme += c;
                    }
                }
            break;
        case 30://digitos
            if (!isMonoLexeme(c, TypeToken::digEnt))
                if (!isBiLexeme(c, TypeToken::digEnt)){
                    lexeme += c;
                    if (c == '.') state = 31;
                    if (!isdigit(c)){
                        state = 99;
                        lexeme += c;
                    }
                }
            break;
        case 31: //por lo menos un digito
            if (!isMonoLexeme(c, TypeToken::invalido))
                if (!isBiLexeme(c, TypeToken::invalido)){
                    lexeme += c;
                    if (isdigit(c)) state = 32;
                    else state = 99;
                }
            break;
        case 32: // digito real x.{x}1
            if (!isMonoLexeme(c, TypeToken::digReal))
                if (!isBiLexeme(c, TypeToken::digReal)){
                    lexeme += c;
                    if (!isdigit(c)) state = 99;
                }
            break;
		case 40: // es una cadena "{x}*
		    if (c == '"')
                saveLexeme(TypeToken::cadena);
		    else if (c == '\n')
		        saveLexeme(TypeToken::invalido);
		    else
                lexeme += c;
            break;
        case 41: // es una cadena '{x}*
		    if (c == '\''){
                if (lexeme.size()!=1)
                    saveLexeme(TypeToken::invalido);
                else
                    saveLexeme(TypeToken::caracter);
		    } else if (c == '\n')
		        saveLexeme(TypeToken::invalido);
            else
                lexeme += c;
            break;
        case 50: // &
            if (c == '&')
                saveLexeme(TypeToken::logico);
            else{
                isBreaker = true;
                saveLexeme(TypeToken::binario);
            }
            break;
        case 51: // |
            if (c == '|')
                saveLexeme(TypeToken::logico);
            else{
                isBreaker = true;
                saveLexeme(TypeToken::binario);
            }
            break;
        case 99: //dato invalido
            if (!isMonoLexeme(c, TypeToken::invalido))
                if (!isBiLexeme(c, TypeToken::invalido)){
                    lexeme += c;
                }
            break;
		default:
			break;
		}

	}
	fs.close();
	return true;
}

bool LexicalAnalyzer::isMonoLexeme(char c, TypeToken t)
{
    TypeToken temp;
    if (c == '+') temp = TypeToken::suma;
    else if (c == '-') temp = TypeToken::resta;
    else if (c == '*') temp = TypeToken::multi;
    else if (c == '%') temp = TypeToken::modulo;
    else if (c == '(') temp = TypeToken::parIzq;
    else if (c == ')') temp = TypeToken::parDer;
    else if (c == '{') temp = TypeToken::llaIzq;
    else if (c == '}') temp = TypeToken::llaDer;
    else if (c == '[') temp = TypeToken::corIzq;
    else if (c == ']') temp = TypeToken::corDer;
    else if (c == ',') temp = TypeToken::coma;
    else if (c == ';') temp = TypeToken::finInst;
    else if (c == '?') temp = TypeToken::opeTer;
    else if (c == '.') temp = TypeToken::punto;
    else if (c == ' ') temp = TypeToken::invalido;
    else if (c == '\n') temp = TypeToken::invalido;
    else
        return false;

    if (t != TypeToken::vacio) saveLexeme(t);
    if (temp != TypeToken::invalido){
        lexeme = c;
        saveLexeme(temp);
    }
    if (c == '\n') ++line;
    return true;
}

bool LexicalAnalyzer::isBiLexeme(char c, TypeToken t){

    if (c == '/') state = 1;
    else if (c == '<') state = 10;
    else if (c == '>') state = 13;
    else if (c == '=') state = 11;
    else if (c == '!') state = 12;
    else if (c == '&') state = 50;
    else if (c == '|') state = 51;
    else return false;
    if (t != TypeToken::vacio)
        saveLexeme(t);
    lexeme = c;
    return true;
}

void LexicalAnalyzer::printAll(){
    for (unsigned int i=0; i<myTokens.size(); ++i)
        cout << "token "<< myTokens[i]->token<<" " << " lexeme: " << myTokens[i]->value<<'\t'<< myTokens[i]->line<< endl;
}

void LexicalAnalyzer::saveLexeme(TypeToken code)
{
    Token *t = new struct Token;
    t->token = code;
    t->line = line;
    if (code == TypeToken::id){
        if (lexeme == "int")
            t->token = TypeToken::palInt;
        else if (lexeme == "char")
            t->token = TypeToken::palChar;
        else if (lexeme == "bool")
            t->token = TypeToken::palBool;
        else if (lexeme == "if")
            t->token = TypeToken::palIf;
        else if (lexeme == "else")
            t->token = TypeToken::palElse;
        else if (lexeme == "void")
            t->token = TypeToken::palVoid;
        else if (lexeme == "return")
            t->token = TypeToken::palReturn;
        else if (lexeme == "while")
            t->token = TypeToken::palWhile;
        else if (lexeme == "for")
            t->token = TypeToken::palFor;
    }
    t->value = lexeme;
    myTokens.push_back(t);
    lexeme = "";
    state = 0;
}
