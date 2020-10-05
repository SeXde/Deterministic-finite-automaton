#pragma once

#include <iostream>
#include<cstring>

using namespace std;

class Lenguaje {

	int numEstados;
	int numSimbolos;
	int numEstadosFinales;
	char * simbolos;
	char * estados;
	char estadoInicial;
	char * estadosFinales;
	char ** tablaT;
	void DefSimbolos();
	void DefEstados();
	void DefTablaT();
	char EstadoSig(char estadoActual, char simboloEntrada);
	bool EsEstadoFinal(char estado);

public:

	Lenguaje();
	void MostrarSimbolos();
	void MostrarEstados();
	void MostrarTablaT();
	void PalabraPertenece();
	virtual ~Lenguaje();

};
