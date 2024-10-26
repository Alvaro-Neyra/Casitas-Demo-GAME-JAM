#include "Rectangulo.h"

Rectangulo::Rectangulo(int x, int y, int lado1, int lado2, int color, int drawType):Figura(x, y, color, drawType) {
	this->lado1 = lado1;
	this->lado2 = lado2;
	this->dx = 10;
	this->dy = 8;
}

Rectangulo::~Rectangulo() {

}

void Rectangulo::dibujar(Graphics^ panel) {
    Color colorFigura;
    switch (color) {
    case 1: colorFigura = Color::Red; break;
    case 2: colorFigura = Color::Green; break;
    case 3: colorFigura = Color::Blue; break;
    case 4: colorFigura = Color::Yellow; break;
    case 5: colorFigura = Color::Purple; break;
    case 6: colorFigura = Color::Orange; break;
    case 7: colorFigura = Color::Brown; break;
    case 8: colorFigura = Color::DarkBlue; break;
    case 9: colorFigura = Color::DarkGreen; break;
    case 10: colorFigura = Color::Black; break;
    default: colorFigura = Color::White; break;
    }
        switch (drawType) {
        case 1: {
            SolidBrush^ brocha = gcnew SolidBrush(colorFigura);
            panel->FillRectangle(brocha, x, y, lado1, lado2);
            break;
        }
        case 2: {
            Pen^ pencil = gcnew Pen(colorFigura);
            panel->DrawRectangle(pencil, x, y, lado1, lado2);
            SolidBrush^ rellenar = gcnew SolidBrush(Color::White);
            panel->FillRectangle(rellenar, x, y, lado1, lado2);
            break;
        }
        }
}


void Rectangulo::borrar(Graphics^ panel) {
    switch (drawType) {
    case 1: {
        SolidBrush^ brocha = gcnew SolidBrush(Color::White);
        panel->FillRectangle(brocha, x, y, lado1, lado2);
        break;
    }
    case 2: {
        Pen^ pencil = gcnew Pen(Color::White);
        panel->DrawRectangle(pencil, x, y, lado1, lado2);
        break;
    }
    }
}


