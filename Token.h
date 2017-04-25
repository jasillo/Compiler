#include <string>
#include <iostream>

using namespace std;

enum TypeToken
{
	inva, //invalido
	pint,
	pcha,
	pboo,
	piff,
	pels,
	pvoi,
	pret,
	pwhi,
	pfor,
	pusi, //using
	pnam, //namespace
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
