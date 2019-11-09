#pragma once
#include<iostream>
using namespace std;
#include "SFML/Graphics.hpp"
using namespace sf;
class Boton
{
private:
	float x, y, alto, ancho, tx, ty;
	string accion;
	string texto;
	Texture* texture;
	Sprite* sprite;
	Text* text;

public:
	Boton(string accion, string texto, float x, float y, string url, float tx, float ty);
	Boton(string accion, string texto, float x, float y, string url, float tx, float ty, float scaleX, float scaleY);
	Boton(string accion, string texto, float x, float y, string url, float tx, float ty, float scaleX, float scaleY, float orX, float orY);
	Boton(string accion, float x, float y, string url, float scaleX, float scaleY);
	Boton(string accion, float x, float y, string url, float scaleX, float scaleY, float orX, float orY);

	void setX(float x);
	void setY(float y);
	void setAlto(float alto);
	void setAncho(float ancho);
	void setTX(float tx);
	void setTY(float ty);
	void setAccion(string accion);
	void setTexto(string texto);
	void setTexture(string url);
	void setSprite(string url);
	void setText(string texto);
	void setColorJPG(int a, int b , int c);
	void setColorPNG(int a, int b, int c, int d);

	void setPosicionSprite(float x, float y);
	void setPosicionTexto(float tx, float ty);



	float getX();
	float getY();
	float getAlto();
	float getAncho();
	float getTX();
	float getTY();
	Texture*& getTexture();
	Sprite *&getSprite();
	Text*& getText();
	string getAccion();



	bool ajustarBtnTexto();
};


