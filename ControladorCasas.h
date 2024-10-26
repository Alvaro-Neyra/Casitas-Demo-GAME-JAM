#pragma once
#include "Casa.h"
#include "Casa1.h"
#include "Casa2.h"
#include "Casa3.h"
#include "vector"


using namespace System::Drawing;
using namespace System;
using namespace std;

class ControladorCasas
{
private:
	vector<Casa*> casas;
	bool destruir = false;
public:
	ControladorCasas();
	~ControladorCasas();

	void agregarCasas(Graphics^ panel, char tipoCasa);
	void dibujarCasas(Graphics^ panel);
	void destruirCasas(Graphics^ panel);
	void setDestruir(bool destruir);
	bool getDestruir();
};

