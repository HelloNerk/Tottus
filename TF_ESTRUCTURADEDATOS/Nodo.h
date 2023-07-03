#pragma once
#include <iostream>
using namespace std;

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* sig = NULL) {
		dato = v;
		siguiente = sig;
	}
};
