#pragma once
#include "Figura.h"
class Triangulo : public Figura
{
private:
	int ancho, alto;

public:
	Triangulo(int x, int y, int ancho, int alto, int color, int drawType);
	~Triangulo();

	void dibujar(Graphics^ panel) override;
	void borrar(Graphics^ panel) override;
	
};
