#include "Casa.h"


Casa::Casa() {
	activar = false;
	destruir = false;
	colorVentana = 10;

	colores = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };


	// Color::Red --> 1
	// Color::Green --> 2
	// Color::Blue --> 3
	// Color::Yellow --> 4
	// Color::Purple --> 5
	// Color::Orange --> 6
	// Color::Brown --> 7
	// Color::DarkBlue --> 8
	// Color::DarkGreen --> 9
	// Color::Black --> 10

	vector<int*> coloresPartesCasa = { &colorTecho, &colorFachada, &colorPared, &colorPuerta };

	for (int* colorParte : coloresPartesCasa) {
		int min = 0;
		int max = colores.size() - 1;
		int indiceAleatorio = min + rand() % (max - min + 1);
		*colorParte = colores[indiceAleatorio];
		colores.erase(colores.begin() + indiceAleatorio);
	}
}
Casa:: ~Casa() {}

void Casa::activarMov() {
	activar = true;
}
void Casa::desactivarMov() {
	activar = false;
}
bool Casa::getActivar() {
	return activar;
}

void Casa::noDestruir() {
	this->destruir = false;
	this->fachada->setDestruir(false);
	this->techo->setDestruir(false);
	this->fachadaFrontal->setDestruir(false);
	this->pared->setDestruir(false);
	this->puerta->setDestruir(false);
	this->ventana->setDestruir(false);
	this->desactivarMov();
}

void Casa::destruirTodo() {
	destruir = true;
}

bool Casa::getDestruir() {
	return this->destruir;
}

