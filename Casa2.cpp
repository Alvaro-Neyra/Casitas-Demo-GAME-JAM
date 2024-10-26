#include "Casa2.h"

Casa2::Casa2() {
	this->fachada = new Rectangulo(634, 800, 65, 61, colorPared, 1);
	this->techo = new Trapecio(880, 348, 110, 60, 1, colorTecho, 1 + rand() % (2 - 1 + 1));
	this->fachadaFrontal = new Triangulo(632, 300, 67, 61, colorFachada, 1);
	this->pared = new Rectangulo(500, 408, 75, 61, colorPared, 1);
	this->puerta = new Rectangulo(551, 430, 30, 40, colorPuerta, 1);
	this->ventana = new Rectangulo(715, 300, 40, 20, colorVentana, 2);
}

Casa2::~Casa2() {

}

void Casa2::dibujarCasa(Graphics^ panel) {
	if (this->getActivar() == false) {
		panel->DrawString("Casa 2", gcnew Font("Arial", 10), Brushes::Black, 672, 300);
	}
	fachada->dibujar(panel);
	techo->dibujar(panel);
	fachadaFrontal->dibujar(panel);
	pared->dibujar(panel);
	puerta->dibujar(panel);
	ventana->dibujar(panel);
}

void Casa2::borrarCasa(Graphics^ panel) {
	fachada->borrar(panel);
	techo->borrar(panel);
	fachadaFrontal->borrar(panel);
	pared->borrar(panel);
	puerta->borrar(panel);
	ventana->borrar(panel);
}

void Casa2::moverCasa(Graphics^ panel) {
	if (this->getActivar() == false) { // Si no esta destruido
		fachada->mover(panel, 410, 4);
		techo->mover(panel, 666, 2);
		fachadaFrontal->mover(panel, 346, 3);
		pared->mover(panel, 691, 1);
		puerta->mover(panel, 650, 1);
		ventana->mover(panel, 420, 3);
	}
}

void Casa2::destruirCasa(Graphics^ panel) {
	this->activarMov();
	fachada->mover(panel, panel->VisibleClipBounds.Height + 20, 3); // Abajo
	techo->mover(panel, panel->VisibleClipBounds.Height + 20, 3);
	fachadaFrontal->mover(panel, -10, 4); // ARRIBA
	pared->mover(panel, -10, 4);
	puerta->mover(panel, panel->VisibleClipBounds.Height + 20, 3);
	ventana->mover(panel, -10, 4); // Arriba
	verificarCoordenadasDeDestruccion(panel);
}

void Casa2::verificarCoordenadasDeDestruccion(Graphics^ panel) {
	if (fachada->getY() >= panel->VisibleClipBounds.Height + 20) {
		fachada->setDestruir(true);
	}

	if (techo->getY() >= panel->VisibleClipBounds.Height + 20) {
		techo->setDestruir(true);
	}

	if (fachadaFrontal->getY() <= -10) {
		fachadaFrontal->setDestruir(true);
	}

	if (pared->getY() <= -10) {
		pared->setDestruir(true);
	}

	if (puerta->getY() >= panel->VisibleClipBounds.Height + 20) {
		puerta->setDestruir(true);
	}

	if (ventana->getY() <= -10) {
		ventana->setDestruir(true);
	}

	if (fachada->getDestruir() && techo->getDestruir() && fachadaFrontal->getDestruir() && pared->getDestruir() && puerta->getDestruir() && ventana->getDestruir()) {
		destruirTodo();
	}
}