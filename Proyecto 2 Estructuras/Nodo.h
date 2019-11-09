#pragma once
class Nodo
{
private:
	int id;
	int x, y, pesoIzq, pesoDer, pesoAr, pesoAb;
	float px, py;

public:
	Nodo();
	Nodo(int id, int x, int y, float peso);

	void setId(int id);
	void setX(int x);
	void setY(int y);
	void setPx(float px);
	void setPy(float py);
	void setPesoIzq(int cont);
	void setPesoAr(int cont);
	void setPesoDer(int cont);
	void setPesoAb(int cont);

	int getId();
	int getX();
	int getY();
	float getPx();
	float getPy();
	int getPesoAr();
	int getPesoAb();
	int getPesoIzq();
	int getPesoDer();

};

