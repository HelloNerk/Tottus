#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

template<class T>
class Lista {
private:
	Nodo<T>* inicio;
	T dato;
	uint lon;
public:
	Lista() { inicio = nullptr; }
	uint getlon();
	void push(T dato);
	void popPos(uint n);
	void print(function<void(T)> imprimir);
};

template<class T>
uint Lista<T>::getlon() {
	return lon;
}

template<class T>
void Lista<T>::push(T dato) {
	Nodo<T>* nuevo = new Nodo<T>(dato, inicio);
	if (nuevo != nullptr) {
		inicio = nuevo;
		lon++;
	}
}

template<class T>
void Lista<T>::popPos(uint n) {
	if (inicio == NULL || n >= lon) {
		return
	}
	n--;
	Nodo<T>* temp1 = nullptr;
	if (n == 0) {
		temp1 = inicio;
		inicio = inicio->siguiente;
	}
	else {
		temp1 = inicio;
		for (int i = 0; i < n - 1; i++) {
			temp1 = temp1->siguiente;
		}
	}

	Nodo<T>* temp2 = temp1->siguiente;
	temp1->siguiente = temp2->siguiente;
	delete temp2;
	lon--;
}

template<class T>
void Lista<T>::print(function<void(T)> imprimir) {
	Nodo<T>* aux = inicio;
	while (aux != NULL)
	{
		imprimir(aux->dato);
		aux = aux->siguiente;
	}
}