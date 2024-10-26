#include "Figura.h"

Figura::Figura(int x, int y, int color, int drawType) {
    this->x = x;
    this->y = y;
    this->dx = 3;
    this->dy = 3;
    this->drawType = drawType;
    //this->drawType = 1 + rand() % (2 - 1 + 1);
    this->color = color;
    this->destruir = false;
}

//int numeroAleatorio(int min, int max) {
//    return min + rand() % (max - min + 1);
//}

Figura::~Figura() {}

void Figura::mover(Graphics^ panel, int coordernadas, int tipo) {

    switch (tipo)
    {
        case 1: { //derecha
            if (x < coordernadas) {
                x += dx;
            }
            break;
        }
        case 2: { //izquierda
            if (x > coordernadas) {
                x -= dx;
            }
            break;
        }

        case 3: { //abajo
            if (y < coordernadas) {
                y += dy;
            }
            break;
        }

        case 4: { //arriba
            if (y > coordernadas) {
                y -= dy;
            }
            break;
        }
    }
}

int Figura::getX() {
    return this->x;
}
int Figura::getY() {
    return this->y;
}

void Figura::setDestruir(bool destruir) {
    this->destruir = destruir;
}

bool Figura::getDestruir() {
    return this->destruir;
}



