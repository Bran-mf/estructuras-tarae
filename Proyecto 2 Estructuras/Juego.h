#pragma once
#include "Boton.h"
#include "Mapa.h"
#include "Personaje.h"
#include "Pantalla_GameOver.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class Juego
{
private:
	string nombre;
	int rx, ry, fps;
	RenderWindow* rw;
	//referente al scenario
	Mapa* mapa;
	Pantalla_GameOver* pantalla_gameOver;
	char letras[21][19];
	Boton* scenario[21][19];
	Sprite* background;
	Boton* datos[6];
	Sprite* backBanckground;


	//referente a los personajes
	Personaje* pacman;
	Personaje* fantasmas[4];
	//referente a los personajes

	//referentes a los diferentes tipos de puntos;
	int nivel;
	int vidas;
	int vidasPerdidas;
	int fantasmasMuertos;
	int ptsTotal;
	int tiempo;

	int pacDots;
	//////////////////

	int tiempo_de_poder;//tiempo_de_comer es como un timepo de poder

public:

	Juego(Mapa* mapa, int lvl, string tema);
	//sets y gets
	void setNivel(int nivel);
	void setNombre(string nombre);
	void setRX(int rx);
	void setRY(int ry);
	void setRW(int rx, int ry);
	void setFps(int fps);

	int getNivel();
	string getNombre();
	int getRX();
	int getRY();
	RenderWindow *getRW();
	int getFps();

	int getPtsTotal();
	int getPacdots();


	//sets y gets

	//loop
	void gameLoop();
	void drawer();
	//loop



	//durante el gameplay
	void verificarTiempo_de_comida();
	void verificarPts(int mitadPacDots);
	void terminarJuego();
	bool gameOver();
	void gamePassed();
	//durante el gameplay


	//referente al mapa(texturas,etc)
	void cargarMapaVisual();
	Boton* elegirRutaTextura(char letra, int x, int y);
	Boton *elegirTextura(string accion, string ruta, int x, int y, float sclX, float sclY, float orX, float orY);
	void mostrarScenarioAutomatico();
	void mostrarPacman();
	void mostrarFantasmas();
	//referente al mapa(texturas,etc)

	//Referente a la carga de datos
	int obtenerVidas();
	//Referente a la carga de datos
};

