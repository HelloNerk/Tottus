#pragma once
#include "Producto.h"
#include "Cuenta.h"
#include <vector>


class Ordenes {
private:
	int cantpedidos;
	Cuenta* cuenta;
	vector<Producto*> vecproducto;
	string name;

public:
	Ordenes(Cuenta* cnt, vector<Producto*> vecprd,int n) {
		cuenta = cnt;
		vecproducto = vecprd;
		cantpedidos=n;
	}

	void mostrarPedido() {
		if (cantpedidos <= 9)
			cout << "ORDEN #0" << cantpedidos<<endl;
		else
			cout << "ORDEN #" << cantpedidos<<endl;

		cuenta->mostrar_nombre_apellido_dni();
		cout << endl;
		for (int i = 0; i < vecproducto.size(); i++) {
			vecproducto.at(i)->mostrar_nombre_codigo_precio();
			cout << endl;
		}
		cout << "====================================================";
		cout << endl;
	}

	void mostrarOrdenName() {
		name = cuenta->getName();
		if (cantpedidos <= 9)
			cout << "ORDEN #0" << cantpedidos;
		else
			cout << "ORDEN #" << cantpedidos;
		cout << "-> "<<name << endl;
	}

	void getNombre() {
		cout << cuenta->getName();
	}

	string distrito() {
		return cuenta->getDistrito();
	}
};