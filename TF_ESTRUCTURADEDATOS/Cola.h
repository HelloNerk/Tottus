#pragma once
#include "Nodo.h"
#include <iostream>

using namespace std;

template<class T>
class Cola {
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}
	void enqueue(T v);
	T dequeue();
	bool esVacia();
	void print(function<void(T)> imprimir);
	Nodo<T>* obtenerinicio() { return inicio; }

};

template<class T>
bool Cola<T>::esVacia() {
	return (inicio == NULL);
}

template<class T>
void Cola<T>::enqueue(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nodo;
		fin = inicio;
	}
	else {

		fin->siguiente = nodo;
		fin = nodo;
	}
	nodo = NULL;
}

template<class T>
T Cola<T>::dequeue() {
	T dato = inicio->dato;

	if (inicio == fin) {
		inicio = NULL;
		fin = NULL;
	}
	else {
		inicio = inicio->siguiente;
	}

	return dato;
}

template<class T>
void Cola<T>::print(function<void(T)> imprimir) {
	Nodo<T>* aux = inicio;
	while (aux != NULL)
	{
		imprimir(aux->dato);
		aux = aux->siguiente;
	}
}

