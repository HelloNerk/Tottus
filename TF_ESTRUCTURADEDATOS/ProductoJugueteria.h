#pragma once
#include "Producto.h"
#include <fstream>
#include <sstream>

class ProductoJugueteria :public Producto {
public:
    ProductoJugueteria(const string& archivo, int n) {
        ifstream infile(archivo);
        if (!infile.is_open()) {
            cout << "Error al abrir el archivo " << archivo << endl;
            system("pause");
            return;
        }
        string line;
        int count = 1;
        while (getline(infile, line)) {
            if (count == n) {
                istringstream iss(line);
                getline(iss, Nombre, ',');
                getline(iss, Marca, ',');
                iss >> Precio;
                iss.ignore();
                iss >> Codigo;
                break;
            }
            count++;
        }
        infile.close();
    }
    ~ProductoJugueteria() {}
};