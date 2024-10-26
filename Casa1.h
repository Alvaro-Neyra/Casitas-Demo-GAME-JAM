#pragma once
#include "Casa.h"
#include "Rectangulo.h"
#include "Trapecio.h"
#include "Triangulo.h"

class Casa1 : public Casa
{
public:
	Casa1();
	~Casa1();

	void dibujarCasa(Graphics^ panel) override;
	void moverCasa(Graphics^ panel) override;
	void borrarCasa(Graphics^ panel) override;
	void destruirCasa(Graphics^ panel) override;
	void verificarCoordenadasDeDestruccion(Graphics^ panel) override;
};

