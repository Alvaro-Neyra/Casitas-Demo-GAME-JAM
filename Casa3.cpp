#include "Casa3.h"

Casa3::Casa3() {
	this->fachada = new Rectangulo(1234, 800, 65, 61, colorPared, 1);
	this->techo = new Trapecio(1480, 348, 110, 60, 3, colorTecho, 1 + rand() % (2 - 1 + 1));
	this->fachadaFrontal = new Triangulo(1232, 300, 67, 61, colorFachada, 1);
	this->pared = new Rectangulo(1100, 408, 75, 61, colorPared, 1);
	this->puerta = new Rectangulo(1151, 430, 30, 40, colorPuerta, 1);
	this->ventana = new Rectangulo(1315, 300, 40, 20, colorVentana, 2);
}

Casa3::~Casa3() {

}

void Casa3::dibujarCasa(Graphics^ panel) {
	if (this->getActivar() == false) {
		panel->DrawString("Casa 3", gcnew Font("Arial", 10), Brushes::Black, 1272, 300);
	}
	fachada->dibujar(panel);
	techo->dibujar(panel);
	fachadaFrontal->dibujar(panel);
	pared->dibujar(panel);
	puerta->dibujar(panel);
	ventana->dibujar(panel);
}

void Casa3::moverCasa(Graphics^ panel) {
	if (this->getActivar() == false) { // Si no esta destruido
		fachada->mover(panel, 410, 4);
		techo->mover(panel, 1266, 2);
		fachadaFrontal->mover(panel, 346, 3);
		pared->mover(panel, 1291, 1);
		puerta->mover(panel, 1250, 1);
		ventana->mover(panel, 420, 3);
	}
}

void Casa3::borrarCasa(Graphics^ panel) {
	fachada->borrar(panel);
	techo->borrar(panel);
	fachadaFrontal->borrar(panel);
	pared->borrar(panel);
	puerta->borrar(panel);
	ventana->borrar(panel);
}

void Casa3::destruirCasa(Graphics^ panel) {
	this->activarMov();
	//switch (tipo)
	//{
	//case 1: { //derecha
	//	if (x < coordernadas) {
	//		x += dx;
	//	}
	//	break;
	//}
	//case 2: { //izquierda
	//	if (x > coordernadas) {
	//		x -= dx;
	//	}
	//	break;
	//}

	//case 3: { //abajo
	//	if (y < coordernadas) {
	//		y += dy;
	//	}
	//	break;
	//}

	//case 4: { //arriba
	//	if (y > coordernadas) {
	//		y -= dy;
	//	}
	//	break;
	//}
	//}
	fachada->mover(panel, -10, 4); // ARRIBA
	techo->mover(panel, panel->VisibleClipBounds.Width + 20, 1); // Derecha
	fachadaFrontal->mover(panel, panel->VisibleClipBounds.Height + 20, 3); // Abajo
	pared->mover(panel, panel->VisibleClipBounds.Height + 20, 3);
	puerta->mover(panel, -10, 4);
	ventana->mover(panel, panel->VisibleClipBounds.Width + 20, 1);
	verificarCoordenadasDeDestruccion(panel);
}

void Casa3::verificarCoordenadasDeDestruccion(Graphics^ panel) {
	if (fachada->getY() <= -10) {
		fachada->setDestruir(true);
	}

	if (techo->getX() >= panel->VisibleClipBounds.Width + 20) {
		techo->setDestruir(true);
	}

	if (fachadaFrontal->getY() >= panel->VisibleClipBounds.Height + 20) {
		fachadaFrontal->setDestruir(true);
	}

	if (pared->getY() >= panel->VisibleClipBounds.Height + 20) {
		pared->setDestruir(true);
	}

	if (puerta->getY() <= -10) {
		puerta->setDestruir(true);
	}

	if (ventana->getX() >= panel->VisibleClipBounds.Width + 20) {
		ventana->setDestruir(true);
	}

	if (fachada->getDestruir() && techo->getDestruir() && fachadaFrontal->getDestruir() && pared->getDestruir() && puerta->getDestruir() && ventana->getDestruir()) {
		destruirTodo();
	}
}