#include "FrmInicio.h"
#include "conio.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main()
{
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew DemoFigurasGraficas::FrmInicio());
	//Project1 es el nombre del proyecto
}