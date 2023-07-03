#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Cuenta {
private:
	string Name;
	string Fullname;
	string dni;
	string email;
	string direccion;
	long long telefono;
	long long tarjeta;
	int cvv;
	string vencimiento;
public:
	Cuenta(string _name, string _fullname, string _dni, string _email, string _direccion, long long _telefono, long long _tarjeta, int _cvv, string _vencimiento) {
		this->Name = _name;
		this->Fullname = _fullname;
		this->dni = _dni;
		this->email = _email;
		this->direccion = _direccion;
		this->telefono = _telefono;
		this->tarjeta = _tarjeta;
		this->cvv = _cvv;
		this->vencimiento = _vencimiento;
	}
	~Cuenta() {}

	void Datos() {
		cout << "Nombre: " << Name << endl;;
		cout << "Apellido: " << Fullname << endl;
		cout << "DNI: " << dni << endl;
		cout << "Email: " << email << endl;
		cout << "Direccion: " << direccion << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Tarjeta: " << tarjeta << endl;
		cout << "CVV: " << cvv << endl;
		cout << "F. Vencimiento: " << vencimiento << endl;
	}

	void mostrar_nombre_apellido_dni() {
		cout << "Nombre: " << Name << endl;
		cout << "Apellido: " << Fullname << endl;
		cout << "DNI: " << dni << endl;
		cout << "Direccion: " << direccion << endl;
	}

	string getName() {
		return Name;
	}

	string getDistrito() {
		return direccion;
	}
};