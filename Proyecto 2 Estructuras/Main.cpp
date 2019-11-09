#include "Controller.h"
#include<fstream>
#include<iostream>
using namespace std;
int main() {
	/*char caracter[21][19];
	ifstream archivo2;
	char letra;
	archivo2.open("datos.txt");
	int fil = 0, col = 0;
	while (!archivo2.eof()) {
		archivo2.get(letra);
		cout << letra;
		
		if (fil < 21) {
			if (col < 19) {
				caracter[fil][col] = letra;
				col++;
				
			}
			else {
				fil++;
				col = 0;
			}
		}
	}
	archivo2.close();
	cout << "ARCHIVO AHORA EN MATRIZ" << endl;
	for (int f = 0; f < 21; f++) {
		for (int c = 0; c < 19; c++) {
			cout << caracter[f][c];
		}
		cout << endl;
	}
	*/

	//Juego* juego = new Juego();
	//EL CONTROLLER SE LLAMA PRIMERO Y SE HACE CON UN CICLO IGUAL QUE EL JUEGO IGUAL QUE SIEMRPE
	//DESPUES, SEGUN LO QU ESE SELECCIONE ENTONCES SE EJECUTA OOOOTRO CICLO Y ASI SUCESIVAMENTE

	
	Controller* controller = new Controller();
	controller = NULL;
	

	///////////////////////////////////////////////////agarrar un dato y pasarlo a un numero
	/*ifstream f;
	string num = "";
	f.open("Game_Files/Lvl/Score/ptj_Total.txt");
	f.seekg(2);
	while (!f.eof()) {
		getline(f, num);
	}

	cout << num << endl;
	stringstream x(num);
	int n;
	x >> n;
	cout << n + 2;*/

	/*
	ifstream f;
	char caracter = ' ';
	f.open("Game_Files/Lvl/Maps/LVL_1.txt");
	bool filasEq = true;
	if (!f.fail()) {
		int fi = 0, c = 0, fa = 0;
		f.get(caracter);
		while (caracter != 'J') {
			fi++;
			f.get(caracter);
		}
		fa = fi;
		f.seekg(0);
		fi = 0;
		
		while (!f.eof() && caracter != 'E' && filasEq == true) {
			f.get(caracter);
			if (caracter != 'J') {
				fi++;
				cout <<"Fila: " << fi << caracter<< endl;
			}
			else {
				f.get(caracter);
				if (fi == fa) {
					fi = 0;
					c++;
					cout << "Columan: " << c << endl;
				}
				else {
					filasEq = false;
				}
				
			}
			

		}
		cout <<endl<< fi << endl << c << endl;
	}
	*/
	
	//////////////////////////////////////datos para mapas
	/*
	ifstream file;

	file.open("Game_Files/Lvl/Maps/LVL_1.txt");
	char letra = ' ';
	bool seguir = true;
	if (!file.fail()) {
		int columnas = 0;
		file.get(letra);
		while (letra != '\n') {
			columnas++;
			file.get(letra);
		}
		file.seekg(0);
		file.get(letra);
		int f = 0, c = 0;
		while (!file.eof() && letra != 'E' && seguir == true) {
			if (letra != '\n') {
				c++;
				cout << c << letra << endl;
				file.get(letra);
			}
			else {
				if (c == columnas) {
					f++;
					c = 0;
					file.get(letra);
					cout << f << endl;
				}
				else {
					seguir = false;
				}

			}
		}
		if (seguir != false) {
			cout << endl << "filas: " << f << " Columas: " << columnas << endl;

			char **letras;
			*letras = new char[f];
			for (int i = 0; i < f; i++) {
				letras[i] = new char[columnas];
			}
			file.seekg(0);
			file.get(letra);

			int fil = 0; int col = 0;
			while (letra != 'E') {
				if (letra != '\n') {
					letras[fil][col] = letra;
					col++;
				}
				else {
					c = 0;
					fil++;
					file.get(letra);
				}
			}

			for (int i = 0; i < f; i++) {
				for (int j = 0; j < c; j++) {
					cout << letras[i][j]<<"  ";
				}
				cout << endl;
			}
		}
	}
	*/


	/*ifstream file;
	char** letras;
	char letra = ' ';
	bool seguir = true;
	int f = 0, fil = 0, c = 0, col = 0;

	file.open("Game_Files/Lvl/Maps/LVL_1.txt");
	if (!file.fail()) {

		file.get(letra);
		while (letra != '\n') {
			c++;
			file.get(letra);
		}

		file.seekg(0);
		file.get(letra);
		while (letra != 'E' && seguir == true && !file.eof()) {
			if (letra != '\n' && col <= c) {
				
				col++;
				file.get(letra);

				if (col > c) {
					seguir = false;
				}

			}else{
				
				if (col == c) {	
					

					fil++;
					col = 0;
					file.get(letra);

				}
				else {
					
					seguir = false;

				}


			}
		}
		if (seguir == true) {
			col = c;
			cout << "Filas: " << fil << " Columnas: " << col << endl;
			letras = new char* [fil];
			for (int i = 0; i < fil; i++) {
				letras[i] = new char[col];
			}
			f = 0;
			c = 0;
			file.seekg(0);
			file.get(letra);
			int contNodos = 0;
			while (letra != 'E' && !file.eof()) {
				if (letra != '\n') {

					if (letra == '#' || letra == '4') {
						contNodos++;
					}

					letras[f][c] = letra;
					c++;
					file.get(letra);
				}
				else {
					c = 0;
					f++;
					file.get(letra);
				}
			}
			for (int i = 0; i < fil; i++) {
				for (int j = 0; j < col; j++) {
					cout << letras[i][j];
				}
				cout << endl;
			}
			cout << "Numero de Nodos: " << contNodos << endl;
		}
		
		
	}

	file.close();
	*/
	return 0;
}