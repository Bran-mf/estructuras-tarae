#pragma once
#include "Boton.h"
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;
class Personaje
{
private:
	int pix, piy;//punto inicial del personaje

	int velocidad;
	int vidas;
	string nombre;
	string ruta;
	Texture* texture;
	Sprite* sprite;
	int movH, movV;
	float x, y;
	bool esperarTecla;
	bool comer;



	Event* accion,* accionAnt;
public:
	Personaje(int vidas, int velocidad, string nombre, float x, float y, string ruta, float scaleX, float scaleY, bool comer);
	//sets y gets
	void setPix(int pix);
	void setPiy(int piy);
	void setVidas(int vidas);
	void setVelocidad(int velocidad);
	void setNombre(string nombre);
	void setTexture(string url);
	void setSprite(Texture* texture);
	void setMovH(int movH);
	void setMovV(int movV);
	void setX(float x);
	void setY(float y);
	void setEsperaTecla(bool esperarTecla);
	void setComer(bool comer);


	int getPix();
	int getPiy();
	int getVidas();
	int getVelocidad();
	string getNombre();
	Texture*& getTexture();
	Sprite*& getSprite();
	int getMovH();
	int getMovV();
	float getX();
	float getY();
	bool getEsperaTecla();
	bool getComer();


	//sets y gets

	
	
	//en cuanto a los esprites
	float getTope();
	float getFondo();
	float getIzquierda();
	float getDerecha();
	//en cuanto a los esprites
	
	
	//metodos propios
	void guardarTecla(Event* evento);
	void selecMov(int mx, int my);
	void verFutColision(Boton *scenario[21][19], int& ptsTotal, int& pacdots, int& fantasmasMuertos, int& vidas, int &vidasPerdidas, Personaje* fantasmas[4]);
	void revisarPosicion(Boton* scenario[21][19], int x, int y, string accion, int& ptsTotal, int &pacdots, int  &fantasmasMuertos, int &vidas, int& vidasPerdidas, Personaje* fantasmas[4]);
	//void adaptarPos_Person_Bloc(Boton* bloque);
	void verColisionConFantasmas(int& ptsTotal, int& fantasmasMuertos, int& vidas, int& vidasPerdidas, Personaje* fantasmas[4]);
	void moverPersonaje(Boton* scenario[21][19], int& ptsTotal, int& pacdots, int& fantasmasMuertos, int& vidas, int& vidasPerdidas, Personaje* fantasmas[4]);
	//metodos propios


};

