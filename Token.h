#include <string>
#include <iostream>

using namespace std;

enum TypeToken
{
	inva, //invalido
	palr, //palabra reservada
	digi, //digito
	cade, //cadena
	iden, //identificador
	comp, //comparacion <, >, == , <=, >=, !=
	suma, //suma o concatenacion +
	rest, //resta -
	divi, //operaciones /
	mult, //multiplicaion *
	modu, //modulo %
	asig, //asignacion =
	pari, //parentesis izquierdo(
	pard, //parentesis derecho )
	llai, //llaves izquierdo {
	llad, //llaves derecha }
	cori, //corchetes izquierdo [
	cord, //corchetes derecho ]
	sepa, //separador ,
	fini, //final de instruccion ;
	opet, //operador ternario ?
	punt, //punto, para acceder a una propiedad
	nega, //negacion
	vaci  //vacio
};

struct Token {
    TypeToken token;
    string value;
};
