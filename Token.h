#include <string>
#include <iostream>

using namespace std;

enum TypeToken
{
	invalido, //invalido 0
	palInt, // pal reservada int
	palChar, //
	palBool, //
	palVoid, // void
	palIf, // pal reservada if
	palElse, // else
	palReturn, // return
	palWhile, // while
	palFor, // for
	palUsing, //using 10
	palNameS, //namespace
	digEnt, //digito
	digReal, //real
	cadena, //cadena
	caracter, //caracter
	id, //identificador
	multi, //multiplicaion *
	divi, //division /
	modulo, //modulo %
	suma, //suma + 20
	resta, //resta -
	comp, //comparacion <, >, == , <=, >=, !=
	logico, //operadores logicos && ||
	binario, // operadores binarios & |
	igual, //igual =
	parIzq, //parentesis izquierdo(
	parDer, //parentesis derecho )
	llaIzq, //llaves izquierdo {
	llaDer, //llaves derecha }
	corIzq, //corchetes izquierdo [ 30
	corDer, //corchetes derecho ]
	coma, //separador ,
	finInst, //final de instruccion ;
	opeTer, //operador ternario ?
	punto, //punto
	neg, //negacion
	incr, //incremento ++
	decr, //decremento --
	vacio  //vacio
};

struct Token {
    TypeToken token;
    int line;
    string value;
};
