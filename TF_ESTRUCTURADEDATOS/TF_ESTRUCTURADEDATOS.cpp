#include "pch.h"
#include "Cuenta.h"
#include "Pila.h"
#include "Controller.h"
#include "Menu.h"
#include <conio.h>
using namespace System;

private enum Tecnologia {
    Celular = 1,
    Televisor = 2,
    Laptop = 3,
    Refrigeradora = 4,
    TecnologiaVolver = 5                    
};

int main()
{
    Controller* controller = new Controller();
    srand(time(NULL));
    bool end = true;
    Menu* menu = new Menu();
    int opcion;
    while (end == true) {

        opcion = menu->MenuInicio();
        //do {
        //    system("cls");
        //    menu->MenuInicio();
        //    cin >> opcion;
        //} while (opcion < 1 || opcion>5);

        if (opcion == 1) {
            system("cls");
            short int opcioncategorias;
            short int opciontecnologia;
            short int opcionropa;
            short int opcioncomida;
            short int opcionjugueteria;
            do {
                opcioncategorias = menu->MenuCategorias2();
                rlutil::setCursorVisibility(true);
                if (opcioncategorias == 1) {
                    system("cls");
                    do {
                        menu->MenuTecnologia();
                        cin >> opciontecnologia;
                    } while (opciontecnologia < 1 || opciontecnologia>35);
                    if (opciontecnologia != 35) controller->agregarProducto(opcioncategorias, opciontecnologia);
                    if (opciontecnologia == 35)cout << "Volviendo a categoria";
                    Sleep(500);
                }
                if (opcioncategorias == 2) {

                    system("cls");
                    do {
                        menu->MenuRopa();
                        cin >> opcionropa;
                    } while (opcionropa < 1 || opcionropa>35);
                    if (opcionropa != 35) controller->agregarProducto(opcioncategorias, opcionropa);
                    if (opcionropa == 35)cout << "Volviendo a categoria";
                    Sleep(500);
                }
                if (opcioncategorias == 3) {

                    system("cls");
                    do {
                        menu->MenuComidas();
                        cin >> opcioncomida;
                    } while (opcioncomida < 1 || opcioncomida>35);
                    if (opcioncomida != 35) controller->agregarProducto(opcioncategorias, opcioncomida);
                    if (opcioncomida == 35)cout << "Volviendo a categoria";
                    Sleep(500);
                }
                if (opcioncategorias == 4) {

                    system("cls");
                    do {
                        menu->MenuJugueteria();
                        cin >> opcionjugueteria;
                    } while (opcionjugueteria < 1 || opcionjugueteria>35);
                    if (opcionjugueteria != 35) controller->agregarProducto(opcioncategorias, opcionjugueteria);
                    if (opcionjugueteria == 35)cout << "Volviendo a categoria";
                    Sleep(500);
                }
                if (opcioncategorias == 5) {
                    system("cls");
                    controller->buscarProductoPorPrecio();
                    system("pause>0");
                }
            } while (opcioncategorias != 6);
        }
        if (opcion == 2) {
            short int opcioncarritocompras;
            system("cls");
            opcioncarritocompras = menu->MenuCarritodeCompras2();
            if (opcioncarritocompras == 1) { controller->imprimirProductos(); }
            if (opcioncarritocompras == 2) { system("cls"); controller->RadixSortporPrecio(); }
            if (opcioncarritocompras == 3) { system("cls"); controller->HeapSortporCodigo(); }
            if (opcioncarritocompras == 4) { controller->buscarProductoPorNombre(); }
            if (opcioncarritocompras == 5) { controller->buscarProductoPorCodigo(); }
            if (opcioncarritocompras == 6) { controller->eliminarProducto(); }
            if (opcioncarritocompras == 7) { rlutil::cls(); menu->LogoTottus(); controller->pagarProductos(); controller->clearProductos(); }
            system("pause>0");
        }
        if (opcion == 3) {
            system("cls");
            cout << "::::ORDENES:::::" << endl;
            controller->imprimirOrdenes();
            system("pause>0");
        }
        if (opcion == 4) {
            system("cls");
            controller->datasetOrdenes();
            system("pause>0");
        }
        if (opcion == 5) {
            controller->GrafosOrdenes();
            system("pause>0");
        }
        if (opcion == 6) {
            menu->Creditos();
            system("pause>0");
        }
        if (opcion == 7) {
            end = false;
        }
    }
    return 0;


}
