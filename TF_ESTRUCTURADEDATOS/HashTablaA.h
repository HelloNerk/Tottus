#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "HashEntidad.h"
using namespace std;

typedef unsigned int size_t;

class HashTablaA {
private:
    vector<list<HashEntidad>> theLists;   // Tabla
    int  currentSize;

public:
    explicit HashTablaA(int size = 101) : currentSize{ 0 }
    {
        theLists.resize(101);
    }

    void makeEmpty()
    {
        for (auto& thisList : theLists)
            thisList.clear();
    }

    bool insert(HashEntidad&& x)
    {
        auto& whichList = theLists[myhash(x.getKey())]; //Obtenemos la lista de elementos según el hash obtenido

        whichList.push_back(x); //Agregamos el nuevo elemento a la lista

        return true;
    }

    void DispAll() {
        int pos = 0;
        for (auto& thisList : theLists) {
            cout << "Producto: " + to_string(pos) << " | ";
            for (auto& it : theLists[pos]) {
                cout << it.getValue() << ",";
            }
            cout << endl;
            pos++;
        }
    }

    void buscar(int codigo) {
        int pos = 0;
        bool stop = false;
        for (auto& thisList : theLists) {
            for (auto& it : theLists[pos]) {
                if (codigo == it.getKey()) {
                    cout << "Producto: ";
                    cout << it.getValue();
                    stop = true;
                    break;
                }
            }
            if (stop == true) break;
            pos++;
        }
        if (stop == false) { cout << "El codigo de producto ingresado no se encuentra en su carrito de compras."; }
    }

private:

    size_t myhash(const int key) const {
        //FUNCION HASH DIGITOSMEDIOS
        size_t cuadrada = key*key;
        size_t hashVal = (cuadrada / 101) % theLists.size();
        //hashVal = 10; //Prueba para verificar como se almacenan los elementos si obtienen el mismo hash
        return(hashVal);
    }


};