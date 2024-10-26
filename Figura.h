#pragma once
#include <iostream>
#include <random>

using namespace std;
using namespace System::Drawing;

class Figura
{
protected:
	int x, y, dx, dy;
	int type;
	int drawType;
	int color;
	bool destruir;
public:
	Figura(int x, int y, int color, int drawType);
	~Figura();

	virtual void dibujar(Graphics^ panel) = 0;
	virtual void borrar(Graphics^ panel) = 0;

	void mover(Graphics^ panel, int coordernadas,int tipo);
	
	int getX();
	int getY();
	void setDestruir(bool destruir);
	bool getDestruir();
};
