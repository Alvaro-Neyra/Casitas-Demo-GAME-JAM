#pragma once
#include <vector>
#include "Rectangulo.h"
#include "Trapecio.h"
#include "Triangulo.h"

using namespace std;

class Casa
{

protected:
	Rectangulo* fachada;
	Trapecio* techo;
	Triangulo* fachadaFrontal;
	Rectangulo* pared;
	Rectangulo* puerta;
	Rectangulo* ventana;
	bool activar;
	bool destruir;
	int colorTecho;
	int colorFachada;
	int colorPared;
	int colorPuerta;
	int colorVentana;
	vector<int> colores;
public:
	Casa();
	~Casa();

	virtual void dibujarCasa(Graphics^ panel) = 0;
	virtual void moverCasa(Graphics^ panel) = 0;
	virtual void borrarCasa(Graphics^ panel) = 0;
	virtual void destruirCasa(Graphics^ panel) = 0;
	virtual void verificarCoordenadasDeDestruccion(Graphics^ panel) = 0;
	void activarMov();
	void desactivarMov();
	bool getActivar();
	void destruirTodo();
	void noDestruir();
	bool getDestruir();
};

