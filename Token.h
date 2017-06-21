#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <iostream>

using namespace std;

enum TypeToken
{
    vacio, //vacio $ 0
    tVoid, // void
    tipodato, // int float bool char
    parIzq, //parentesis izquierdo(
	parDer, //parentesis derecho )
	corIzq, //corchetes izquierdo [
	corDer, //corchetes derecho ]
	igual, //igual =
	igualoper, //+= -= *= /=
	coma, //separador ,
	finInst, //final de instruccion ; 10
	id, //identificador
	llaIzq, //llaves izquierdo {
	llaDer, //llaves derecha }
	palIf, // pal reservada if
	palWhile, // while
	palBreak,
	palElse, // else
	digEnt, //digito
	digReal, //real
	booleano, //true false 20
	cadena, //cadena
	logico, //operadores logicos && ||
	comp, //comparacion <, >, == , <=, >=, !=
	suma, //suma y resta + - 20
	modulo, //modulo %
	multi, //multiplicaion y division * /
	caracter, //caracter
	palReturn, // return

	binario, // operadores binarios & |
	opeTer, //operador ternario ?
	neg, //negacion

    invalido, //invalido 32
	S, //33
	S_,
	Ar,
	Ar_,
	Ar__,
	Ar___,
	Ld,
	P, //40
	P_,
	F,
	Li,
	I,
	B,
	B_,
	Le,
	Le_,
	E,
	L, //50
	Co,
	Su,
	Mo,
	M,
	Si,
	D,
	D_

};

struct Token {
    TypeToken token;
    int line = 0;
    string value ="";
};

#endif
