#include "Triangulo.h"

Triangulo::Triangulo(int x, int y, int ancho, int alto, int color, int drawType) :Figura(x, y, color, drawType) {
    this->ancho = ancho;
    this->alto = alto;
}

Triangulo::~Triangulo() {}

void Triangulo::dibujar(Graphics^ panel) {
    // Se especifica el array correcto para usar en este contexto (en este caso de cli)
    cli::array<Point>^ puntos = gcnew cli::array<Point>(3) {
        Point(x + (ancho / 2), y),
            Point(x, y + alto),
            Point(x + ancho, y + alto)
    };

    switch (color) {
    case 1: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Red);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Red);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 2: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Green);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Green);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 3: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Blue);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Blue);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 4: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Yellow);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Yellow);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 5: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Purple);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Purple);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 6: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Orange);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Orange);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 7: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Brown);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Brown);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 8: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::DarkBlue);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::DarkBlue);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 9: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::DarkGreen);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::DarkGreen);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 10: {
        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(Color::Black);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(Color::Black);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    }

    
}

void Triangulo::borrar(Graphics^ panel) {
    cli::array<Point>^ puntos = gcnew cli::array<Point>(3) {
        Point(x + (ancho / 2), y),
            Point(x, y + alto),
            Point(x + ancho, y + alto)
    };

    SolidBrush^ brocha = gcnew SolidBrush(Color::White);
    panel->FillPolygon(brocha, puntos);
}
