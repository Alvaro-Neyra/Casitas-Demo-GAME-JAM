#include "ControladorCasas.h"

ControladorCasas::ControladorCasas() {}

ControladorCasas::~ControladorCasas() {}


void ControladorCasas::agregarCasas(Graphics^ panel, char tipoCasa) {
    Casa* casa;
    panel->Clear(Color::White);
    setDestruir(false);
    switch (tipoCasa)
    {
    case 'C':
        casa = new Casa1();
        break;
    case 'T':
        casa = new Casa2();
        break;
    case 'D':
        casa = new Casa3();
        break;
    }
    casas.push_back(casa);
}

void ControladorCasas::dibujarCasas(Graphics^ panel) {
    panel->Clear(Color::White);
    for each (Casa * casa in casas)
    {
        casa->borrarCasa(panel);
        casa->moverCasa(panel);
        casa->dibujarCasa(panel);
    }
}

void ControladorCasas::destruirCasas(Graphics^ panel) {
    if (destruir) {
        panel->Clear(Color::White);

        for (int i = casas.size() - 1; i >= 0; --i) {
            Casa* casa = casas[i];

            casa->borrarCasa(panel);
            casa->destruirCasa(panel);
            casa->dibujarCasa(panel);

            if (casa->getDestruir()) {
                casa->borrarCasa(panel);
                casa->noDestruir();
                casa->desactivarMov();
                casas.erase(casas.begin() + i);
            }
        }
    }
}

void ControladorCasas::setDestruir(bool destruir) {
    this->destruir = destruir;
}
bool ControladorCasas::getDestruir() {
    return destruir;
}
