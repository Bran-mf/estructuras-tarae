#pragma once
#include "Nodo.h"
#include<iostream>
#include<fstream>
#include <sstream>
using namespace std;
class Mapa
{
private:
	int lvl;
	string ruta;
	char letras[21][19];
	Nodo** grafo;
public:
	Mapa(int lvl);
	char getLetras(int fil, int col);
	Nodo** getGrafo();


	bool verificarTam();
	void inicializarMatLetras();
	void inicializarGrafo();
	void clcPsNd(Nodo*& nodo, int x, int y);

};

