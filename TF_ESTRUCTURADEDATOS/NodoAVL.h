#pragma once

template<typename T>
class NodoAVL {
public:
	T elemento;
	int altura;
	NodoAVL<T>* izquierdo;
	NodoAVL<T>* derecho;

	NodoAVL(const T& elemento) : elemento(elemento), altura(1), izquierdo(nullptr), derecho(nullptr) {}

	void actualizarAltura() {
		int alturaIzq = (izquierdo != nullptr) ? izquierdo->altura : 0;
		int alturaDer = (derecho != nullptr) ? derecho->altura : 0;
		altura = 1 + std::max(alturaIzq, alturaDer);
	}

	int factorBalance() {
		int alturaIzq = (izquierdo != nullptr) ? izquierdo->altura : 0;
		int alturaDer = (derecho != nullptr) ? derecho->altura : 0;
		return alturaIzq - alturaDer;
	}
};

