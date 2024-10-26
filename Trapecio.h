#pragma once
#include "Figura.h"
class Trapecio : public Figura
{
private:
	int ancho, alto;
	int xInicial;
	int tipoTrapecio;
public:
	Trapecio(int x, int y, int ancho, int alto, int tipoTrapecio, int color, int drawType);
	~Trapecio();

	void dibujar(Graphics^ panel) override;
	void borrar(Graphics^ panel) override;
	void setXInicial(int x);
	int getXInicial();
};


