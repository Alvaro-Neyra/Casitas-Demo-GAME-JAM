#include "Trapecio.h"

Trapecio::Trapecio(int x, int y, int ancho, int alto, int tipoTrapecio, int color, int drawType) :Figura(x, y, color, drawType) {
    this->ancho = ancho;
    this->alto = alto;
    this->xInicial = x;
    this->tipoTrapecio = tipoTrapecio;
}

Trapecio::~Trapecio() {}

void Trapecio::dibujar(Graphics^ panel) {
    cli::array<Point>^ puntos = nullptr;

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

    switch (tipoTrapecio) {
    case 1: {
        puntos = gcnew cli::array<Point>(4) {
            Point(x, y),
                Point(x + (ancho / 3), y + alto),
                Point(x + ancho, y + alto),
                Point(x + (ancho * 2 / 3), y)
        };

        if (drawType == 1) {
            SolidBrush^ brocha = gcnew SolidBrush(colorFigura);
            panel->FillPolygon(brocha, puntos);
        }
        else if (drawType == 2) {
            Pen^ lapiz = gcnew Pen(colorFigura);
            panel->DrawPolygon(lapiz, puntos);
        }
        break;
    }
    case 2: {
        puntos = gcnew cli::array<Point>(4) {
            Point(x, y),
                Point(x + (ancho / 3), y + alto),
                Point(x + ancho, y + alto),
                Point(x + (ancho * 2 / 3), y)
        };

        Pen^ lapiz = gcnew Pen(colorFigura);
        panel->DrawPolygon(lapiz, puntos);

        int columnas = 4;
        for (int i = 1; i < columnas; i++) {
            panel->DrawLine(lapiz,
                Point(x + (i * (ancho / columnas - 8)), y),
                Point(x + (i * (ancho / columnas - 8)) + (ancho / 3), y + alto));
        }

        int filas = 5;
        int altoMiniTrapecio = alto / filas;
        for (int i = 1; i < filas; i++) {
            panel->DrawLine(lapiz,
                Point(x + (i * (ancho / 3) / filas), y + (i * altoMiniTrapecio)),
                Point(x + ancho - (ancho / 3) + i * (ancho / 15), y + (i * altoMiniTrapecio))); 
        }
        break;
    }
    case 3: {
        puntos = gcnew cli::array<Point>(4) {
            Point(x, y),
                Point(x + (ancho / 3), y + alto),
                Point(x + ancho, y + alto),
                Point(x + (ancho * 2 / 3), y)
        };

        Pen^ lapiz = gcnew Pen(colorFigura);
        panel->DrawPolygon(lapiz, puntos);

        int filas = 5;
        int altoMiniTrapecio = alto / filas;
        for (int i = 1; i < filas; i++) {
            panel->DrawLine(lapiz,
                Point(x + (i * (ancho / 3) / filas), y + (i * altoMiniTrapecio)),
                Point(x + ancho - (ancho / 3) + i * (ancho / 15), y + (i * altoMiniTrapecio)));
        }
        break;
    }
    }
}

void Trapecio::borrar(Graphics^ panel) {
    cli::array<Point>^ puntos = gcnew cli::array<Point>(4) {
        Point(x, y),
            Point(x + (ancho / 3), y + alto),
            Point(x + ancho, y + alto),
            Point(x + (ancho * 2 / 3), y)
    };

    SolidBrush^ brochaBlanca = gcnew SolidBrush(Color::White);
    panel->FillPolygon(brochaBlanca, puntos);

    if (tipoTrapecio == 2) {
        Pen^ lapizBlanco = gcnew Pen(Color::White);

        int columnas = 4;
        for (int i = 1; i < columnas; i++) {
            panel->DrawLine(lapizBlanco,
                Point(x + (i * (ancho / columnas)), y),
                Point(x + (i * (ancho / columnas)) + (ancho / 3), y + alto));
        }

        int filas = 5;
        int altoMiniTrapecio = alto / filas;
        for (int i = 1; i < filas; i++) {
            panel->DrawLine(lapizBlanco,
                Point(x + (i * (ancho / 3) / filas), y + (i * altoMiniTrapecio)),
                Point(x + ancho - (ancho / 3) + i * (ancho / filas), y + (i * altoMiniTrapecio)));
        }
    }
    else if (tipoTrapecio == 3) {
        Pen^ lapizBlanco = gcnew Pen(Color::White);

        int filas = 5;
        int altoMiniTrapecio = alto / filas;
        for (int i = 1; i < filas; i++) {
            panel->DrawLine(lapizBlanco,
                Point(x + (i * (ancho / 3) / filas), y + (i * altoMiniTrapecio)),
                Point(x + ancho - (ancho / 3) + i * (ancho / filas), y + (i * altoMiniTrapecio)));
        }
    }
}

void Trapecio::setXInicial(int x) {
    this->xInicial = x;
}

int Trapecio::getXInicial() {
    return this->xInicial;
}