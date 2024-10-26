#include "Casa1.h"


Casa1::Casa1() {
	this->fachada = new Rectangulo(134, 800, 65, 61, colorPared, 1);
	this->techo = new Trapecio(380, 348, 110, 60, 2, colorTecho, 1 + rand() % (2 - 1 + 1));
	this->fachadaFrontal = new Triangulo(132, 300, 67, 61, colorFachada, 1);
	this->pared = new Rectangulo(0, 407, 75, 61, colorPared, 1);
	this->puerta = new Rectangulo(51, 430, 30, 40, colorPuerta, 1);
	this->ventana = new Rectangulo(215, 300, 40, 20, colorVentana, 2);

	//int baseXDelTechoTotal = 380;
	//int baseYDelTechoTotal = 48;
	//int anchoBase = 110;
	//int altoTotal = 60;
	//int columnas = 4;
	//int filas = 5;

	//int anchoMiniTrapecio = anchoBase / columnas;
	//int altoMiniTrapecio = altoTotal / filas;

	//for (int i = 0; i < filas; i++) {
	//	for (int j = 0; j < columnas; j++) {
	//		int x = baseXDelTechoTotal + (j * anchoMiniTrapecio) + (i * (anchoMiniTrapecio /4));
	//		int y = baseYDelTechoTotal + (i * altoMiniTrapecio);
	//		int ancho = 22;
	//		int alto = altoMiniTrapecio;

	//		this->partesTecho.push_back(new Trapecio(x, y, ancho, alto));
	//	}
	//}
}

Casa1:: ~Casa1() {}

void Casa1::dibujarCasa(Graphics^ panel) {
	if (this->getActivar() == false) {
		panel->DrawString("Casa 1", gcnew Font("Arial", 10), Brushes::Black, 172, 300);
	}
	fachada->dibujar(panel);	
	techo->dibujar(panel);
	fachadaFrontal->dibujar(panel);
	pared->dibujar(panel);
	puerta->dibujar(panel);
	ventana->dibujar(panel);
}
void Casa1::borrarCasa(Graphics^ panel) {
	fachada->borrar(panel);	
	fachadaFrontal->borrar(panel);
	pared->borrar(panel);
	puerta->borrar(panel);
	techo->borrar(panel);
	ventana->borrar(panel);
}
void Casa1::moverCasa(Graphics^ panel) {
	if (this->getActivar() == false) { // Si no esta destruido
		fachada->mover(panel, 410, 4); // Arriba -390
		techo->mover(panel, 166, 2); // Izquierda -214
		fachadaFrontal->mover(panel, 346, 3); //Abajo +46
		pared->mover(panel, 191, 1); // Derecha +191
		puerta->mover(panel, 150, 1);
		ventana->mover(panel, 420, 3);
	}
}

void Casa1::destruirCasa(Graphics^ panel) {
	this->activarMov();
	fachada->mover(panel, -10, 4);
	techo->mover(panel, -10, 2); // Izquierda
	fachadaFrontal->mover(panel, -20, 2);
	pared->mover(panel, panel->VisibleClipBounds.Height + 20, 3); // Abajo
	puerta->mover(panel, -10, 4); // ARRIBA
	ventana->mover(panel, -10, 2);
	verificarCoordenadasDeDestruccion(panel);
}

void Casa1::verificarCoordenadasDeDestruccion(Graphics^ panel) {
	if (fachada->getY() <= -10) {
		fachada->setDestruir(true);
	}

	if (techo->getX() >= -10) {
		techo->setDestruir(true);
	}

	if (fachadaFrontal->getX() <= -20) {
		fachadaFrontal->setDestruir(true);
	}

	if (pared->getY() >= panel->VisibleClipBounds.Height + 20) {
		pared->setDestruir(true);
	}

	if (puerta->getY() <= -10) {
		puerta->setDestruir(true);
	}

	if (ventana->getX() >= -10) {
		ventana->setDestruir(true);
	}

	if (fachada->getDestruir() && techo->getDestruir() && fachadaFrontal->getDestruir() && pared->getDestruir() && puerta->getDestruir() && ventana->getDestruir()) {
		destruirTodo();
	}
}