#pragma once
#include "ArbolNodo.h"

template<class T>
class Arbol {
public:
    ArbolNodo<T>* raiz;

    Arbol() {
        raiz = NULL;
    }

    void insertar(T dato) {
        if (raiz == NULL) {
            raiz = new ArbolNodo<T>(dato);
        }
        else {
            insertarRecursivo(raiz, dato);
        }
    }

    void insertarRecursivo(ArbolNodo<T>* nodo, T dato) {
        if (dato < nodo->dato) {
            if (nodo->izquierda == NULL) {
                nodo->izquierda = new ArbolNodo<T>(dato);
            }
            else {
                insertarRecursivo(nodo->izquierda, dato);
            }
        }
        else if (dato > nodo->dato) {
            if (nodo->derecha == NULL) {
                nodo->derecha = new ArbolNodo<T>(dato);
            }
            else {
                insertarRecursivo(nodo->derecha, dato);
            }
        }
    }

    bool buscar(T dato) {
        return buscarRecursivo(raiz, dato);
    }

    bool buscarRecursivo(ArbolNodo<T>* nodo, T dato) {
        if (nodo == NULL) {
            return false;
        }
        else if (dato == nodo->dato) {
            return true;
        }
        else if (dato < nodo->dato) {
            return buscarRecursivo(nodo->izquierda, dato);
        }
        else {
            return buscarRecursivo(nodo->derecha, dato);
        }
    }

    int busquedaBinaria(T dato) {
        return busquedaBinariaRecursiva(raiz, dato);
    }

    int busquedaBinariaRecursiva(ArbolNodo<T>* nodo, T dato) {
        if (nodo == NULL) {
            return -1;
        }

        if (dato == nodo->dato) {
            return 0;
        }
        else if (dato < nodo->dato) {
            int resultado = busquedaBinariaRecursiva(nodo->izquierda, dato);
            if (resultado == -1) {
                return -1;
            }
            else {
                return 2 * resultado;
            }
        }
        else {
            int resultado = busquedaBinariaRecursiva(nodo->derecha, dato);
            if (resultado == -1) {
                return -1;
            }
            else {
                return 2 * resultado + 1;
            }
        }
    }
};
