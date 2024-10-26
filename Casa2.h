#pragma once
#include "Casa.h"
#include "Rectangulo.h"
#include "Trapecio.h"
#include "Triangulo.h"

class Casa2 : public Casa
{
public:
	Casa2();
	~Casa2();

	void dibujarCasa(Graphics^ panel) override;
	void moverCasa(Graphics^ panel) override;
	void borrarCasa(Graphics^ panel) override;
	void destruirCasa(Graphics^ panel) override;
	void verificarCoordenadasDeDestruccion(Graphics^ panel) override;

};

