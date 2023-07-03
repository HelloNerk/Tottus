#pragma once
#include "NodoAVL.h"
#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class AVL {
private:

    NodoAVL<T>* raiz;

public:

    AVL() : raiz(nullptr) {}

    NodoAVL<T>* getRaiz() {
        return raiz;
    }

    bool buscar(const T& elemento) {
        return buscarElemento(raiz, elemento);
    }

    void insertar(const T& elemento) {
        insertarElemento(raiz, elemento);
    }

    std::vector<T> busquedaRangoPrecio(double precioMin, double precioMax) {
        std::vector<T> productosEncontrados;
        busquedaRangoPrecioAux(raiz, precioMin, precioMax, productosEncontrados);
        return productosEncontrados;
    }

private:

    NodoAVL<T>* busquedaRangoPrecioAux(NodoAVL<T>* nodo, double precioMin, double precioMax) {
        if (nodo == nullptr) {
            return nullptr;
        }

        if (nodo->elemento.getPrecio() >= precioMin && nodo->elemento.getPrecio() <= precioMax) {
            return nodo;
        }

        if (nodo->elemento.getPrecio() > precioMin) {
            return busquedaRangoPrecioAux(nodo->getIzquierdo(), precioMin, precioMax);
        }

        if (nodo->elemento.getPrecio() < precioMax) {
            return busquedaRangoPrecioAux(nodo->getDerecho(), precioMin, precioMax);
        }

        return nullptr;
    }

    void busquedaRangoPrecioAux(NodoAVL<T>* nodo, double precioMin, double precioMax, std::vector<T>& productosEncontrados) {
        if (nodo == nullptr) {
            return;
        }

        if (nodo->elemento.getPrecio() >= precioMin && nodo->elemento.getPrecio() <= precioMax) {
            productosEncontrados.push_back(nodo->elemento);
        }

        if (nodo->elemento.getPrecio() > precioMin) {
            busquedaRangoPrecioAux(nodo->izquierdo, precioMin, precioMax, productosEncontrados);
        }

        if (nodo->elemento.getPrecio() < precioMax) {
            busquedaRangoPrecioAux(nodo->derecho, precioMin, precioMax, productosEncontrados);
        }
    }

    bool buscarElemento(NodoAVL<T>* nodo, const T& elemento) {
        if (nodo == nullptr) {
            return false;
        }

        if (elemento == nodo->elemento) {
            return true;
        }
        else if (elemento < nodo->elemento) {
            return buscarElemento(nodo->izquierdo, elemento);
        }
        else {
            return buscarElemento(nodo->derecho, elemento);
        }
    }

    void insertarElemento(NodoAVL<T>*& nodo, const T& elemento) {
        if (nodo == nullptr) {
            nodo = new NodoAVL<T>(elemento);
        }
        else if (elemento < nodo->elemento) {
            insertarElemento(nodo->izquierdo, elemento);
        }
        else {
            insertarElemento(nodo->derecho, elemento);
        }

        nodo->actualizarAltura();

        int balance = nodo->factorBalance();
        if (balance > 1) {
            if (elemento < nodo->izquierdo->elemento) {
                rotacionSimpleDerecha(nodo);
            }
            else {
                rotacionDobleIzquierdaDerecha(nodo);
            }
        }
        else if (balance < -1) {
            if (elemento > nodo->derecho->elemento) {
                rotacionSimpleIzquierda(nodo);
            }
            else {
                rotacionDobleDerechaIzquierda(nodo);
            }
        }
    }

    void rotacionSimpleDerecha(NodoAVL<T>*& nodo) {
        NodoAVL<T>* nodoAux = nodo->izquierdo;
        nodo->izquierdo = nodoAux->derecho;
        nodoAux->derecho = nodo;
        nodo->actualizarAltura();
        nodoAux->actualizarAltura();
        nodo = nodoAux;
    }

    void rotacionSimpleIzquierda(NodoAVL<T>*& nodo) {
        NodoAVL<T>* nodoAux = nodo->derecho;
        nodo->derecho = nodoAux->izquierdo;
        nodoAux->izquierdo = nodo;
        nodo->actualizarAltura();
        nodoAux->actualizarAltura();
        nodo = nodoAux;
    }

    void rotacionDobleIzquierdaDerecha(NodoAVL<T>*& nodo) {
        rotacionSimpleIzquierda(nodo->izquierdo);
        rotacionSimpleDerecha(nodo);
    }

    void rotacionDobleDerechaIzquierda(NodoAVL<T>*& nodo) {
        rotacionSimpleDerecha(nodo->derecho);
        rotacionSimpleIzquierda(nodo);
    }
};


