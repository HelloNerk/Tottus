#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Producto {
protected:
	string Nombre;
	string Marca;
	float Precio;
	int Codigo;
public:
	Producto() {}

	Producto(string nombre, string marca, double precio, int codigo) {
		this->Nombre = nombre;
		this->Marca = marca;
		this->Precio = precio;
		this->Codigo = codigo;
	}
	Producto(int n) {
		this->Nombre = "";
		this->Marca = "";
		this->Precio = 0;
		this->Codigo = 0;
	}

	void DatosProducto() {
		cout << "Nombre: " << Nombre << endl;
		cout << "Marca: " << Marca << endl;
		cout << "Precio (Soles) : " << Precio << endl;
		cout << "Codigo: " << Codigo << endl;
	}

	float getPrecio() {
		return Precio;
	}

	void mostrar_nombre_codigo_precio() {
		cout << "Nombre: " << Nombre << endl;
		cout << "Codigo: " << Codigo << endl;
		cout << "Precio (Soles) : " << Precio << endl;
	}

	char ObtenerPrimeraletra() {
		return Nombre[0];
	}

	int getCodigo() {
		return Codigo;
	}

	string getNombre() {
		return Nombre;
	}

};