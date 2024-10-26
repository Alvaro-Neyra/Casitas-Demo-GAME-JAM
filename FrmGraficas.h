#pragma once
#include "ControladorCasas.h"

namespace DemoFigurasGraficas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmGraficas
	/// </summary>
	public ref class FrmGraficas : public System::Windows::Forms::Form
	{
	public:
		FrmGraficas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			panel = this->CreateGraphics();
			controladorCasas = new ControladorCasas();
			timer1->Enabled = true;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmGraficas()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


		Graphics^ panel;
		ControladorCasas* controladorCasas;

	private: System::Windows::Forms::Timer^ timer1;
		 

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmGraficas::timer1_Tick);
			// 
			// FrmGraficas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1472, 782);
			this->Name = L"FrmGraficas";
			this->Text = L"FrmGraficas";
			this->Load += gcnew System::EventHandler(this, &FrmGraficas::FrmGraficas_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FrmGraficas::FrmGraficas_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmGraficas::FrmGraficas_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmGraficas_Load(System::Object^ sender, System::EventArgs^ e) {
		panel->Clear(Color::White);
	}
	
	private: System::Void FrmGraficas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		panel->Clear(Color::White);
	}


private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	controladorCasas->dibujarCasas(panel);
	controladorCasas->destruirCasas(panel);
}
	private: System::Void FrmGraficas_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::C)
			controladorCasas->agregarCasas(panel, 'C');
		if (e->KeyCode == Keys::D)
			controladorCasas->agregarCasas(panel, 'D');
		if (e->KeyCode == Keys::T)
			controladorCasas->agregarCasas(panel, 'T');
		if (e->KeyCode == Keys::Z)
			controladorCasas->setDestruir(true);
	}
	};
}
