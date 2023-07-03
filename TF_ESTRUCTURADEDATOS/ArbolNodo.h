#pragma once
template <class T>
class ArbolNodo {
public:
    T dato;
    ArbolNodo<T>* izquierda;
    ArbolNodo<T>* derecha;

    ArbolNodo(T dato) {
        this->dato = dato;
        izquierda = NULL;
        derecha = NULL;
    }
};
