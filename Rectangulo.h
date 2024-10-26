#pragma once
#include "Figura.h"
class Rectangulo : public Figura
{
private:
    int lado1, lado2;
public:
    Rectangulo(int x, int y, int lado1, int lado2, int color, int drawType);
    ~Rectangulo();
    void dibujar(Graphics^ panel) override;
    void borrar(Graphics^ panel) override;
    
};


