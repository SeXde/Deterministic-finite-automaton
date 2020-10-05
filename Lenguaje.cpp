#include "Lenguaje.h"

Lenguaje::Lenguaje()
{
	DefSimbolos();
	DefEstados();
	DefTablaT();
}



void Lenguaje::DefSimbolos()
{
		cout << "Introduce el numero de simbolos:  "<<flush;
		cin >> numSimbolos;
		simbolos = new char [numSimbolos];
		for (int i = 0; i<numSimbolos; i++)
		{
			cout <<"Introduce el simbolo "<<i+1<<": "<<flush;
			cin >> simbolos[i];
		}

}

void Lenguaje::MostrarSimbolos()
{
	for (int i = 0; i<numSimbolos; i++)
	{
		cout<<simbolos[i]<<", "<<flush;
	}
}

void Lenguaje::DefEstados()
{

	cout << "Introduce el numero de estados:  "<<flush;
	cin >> numEstados;
	estados = new char [numEstados];

	for (int i = 0; i<numEstados; i++)
	{
		cout <<"Introduce el estado "<<i+1<<": "<<flush;
		cin >> estados[i];
	}

	MostrarEstados();
	cout <<"¿Cual es el estado inicial? "<<flush;
	cin >> estadoInicial;

	cout <<"Introduce el numero de estados finales: "<<flush;
	cin >> numEstadosFinales;
	estadosFinales = new char [numEstadosFinales];
	for (int i = 0; i<numEstadosFinales; i++)
	{
		cout << "Introduce el estado final "<<i+1<<": "<<flush;
		cin >> estadosFinales[i];
		cout <<endl;
	}


}

void Lenguaje::MostrarEstados()
{
	for (int i = 0; i<numEstados; i++)
	{
		cout<<estados[i]<<", "<<flush;
	}
}

void Lenguaje::DefTablaT()
{

	tablaT = new char * [numEstados+1];
	for (int i = 0; i < numEstados+1; i++) tablaT[i] = new char [numSimbolos+1];

	for (int i = 1 ; i < numEstados+1 ; i++) tablaT[i][0] = estados[i-1];

	for (int j = 1; j < numSimbolos+1 ; j++) tablaT[0][j] = simbolos[j-1];

	tablaT[0][0] = 35;

	cout <<"Los estados son: "<<flush;
	MostrarEstados();
	cout << endl;
	cout <<"Los simbolos son: "<<flush;
	MostrarSimbolos();
	cout << endl;

	for (int i = 1; i < numEstados+1; i++)
	{
		for (int j = 1; j < numSimbolos+1; j++)
		{
			cout <<"¿A que estado transita "<<tablaT[i][0]<<" cuando recibe "<<tablaT[0][j]<<" ? "<<flush;
			cin >> tablaT[i][j];
			cout << endl;
		}
	}

}

void Lenguaje::MostrarTablaT()
{
	for(int i = 0; i < numEstados+1; i++)
	{
		for (int j = 0; j<numSimbolos+1; j++)
		{
			cout<<tablaT[i][j]<<" "<<flush;
		}
		cout <<endl;
	}
}

bool Lenguaje::EsEstadoFinal(char estado)
{
	for (int i = 0; i < numEstadosFinales; i++)
	{
		if (estado == estadosFinales[i]) return true;
	}
	return false;
}

char Lenguaje::EstadoSig(char estadoActual, char simboloEntrada)
{
	int i = 1;
	int j = 1;
	while (estadoActual != tablaT[i][0]) i++;
	while (simboloEntrada != tablaT[0][j]) j++;
	return tablaT[i][j];
}

void Lenguaje::PalabraPertenece()
{
	cout <<"Forma una palabra con los siguientes simbolos: "<<flush;
	MostrarSimbolos();
	cout<<endl;
	cout<<"Introduce la palabra: "<<flush;
	string palabra;
	cin >> palabra;
	char estadoFinal = EstadoSig(estadoInicial, palabra[0]);
	for (int i = 1; i<(int)palabra.size(); i++)
	{
		estadoFinal = EstadoSig(estadoFinal, palabra[i]);
	}

	if (EsEstadoFinal(estadoFinal))
	{
		cout<<"La palabra "<<char(34)<<palabra<<char(34)<<" pertenece al lenguaje."<<endl;
	}
	else
	{
		cout<<"La palabra "<<char(34)<<palabra<<char(34)<<" no pertenece al lenguaje."<<endl;
	}

}



Lenguaje::~Lenguaje()
{
	delete [] simbolos;
	delete [] estados;
	delete [] estadosFinales;
	for (int i = 0; i<numEstados; i++) delete [] tablaT[i];
	delete [] tablaT;
}

