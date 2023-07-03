#pragma once
#include <iostream>
#include "Producto.h"
#include "ProductoTecnologia.h"
#include "ProductoComida.h"
#include "ProductoRopa.h"
#include "ProductoJugueteria.h"
#include <vector>
#include "rlutil.h"
#include <Windows.h>
using namespace std;
using namespace System;

class Menu {
private:
	vector<Producto*>vecTecnologia;
	vector<Producto*>vecRopa;
	vector<Producto*>vecComida;
	vector<Producto*>vecJugueteria;
	HANDLE hConsole;
public:
	Menu() {
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 1; i < 35; i++) {
			vecTecnologia.push_back(new ProductoTecnologia("productos_tecnologia.txt", i));
			vecRopa.push_back(new ProductoRopa("productos_ropa.txt", i));
			vecComida.push_back(new ProductoComida("productos_comida.txt", i));
			vecJugueteria.push_back(new ProductoJugueteria("productos_jugueteria.txt", i));
		}
	}
	~Menu() {}

	void showItem(const char* text, int posx,int posy,bool selected) {
		if (selected) {
			rlutil::setBackgroundColor(rlutil::COLOR::GREEN);
		}else {
			rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		}
		
		rlutil::locate(posx, posy);
		cout << text << endl;
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
	}

	void MenuInicio2() {
		int y = 0;
		rlutil::hidecursor();
		rlutil::cls();
		int op = 1;
		while (op!=0) {
			rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
			rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
			LogoTottus();
			rlutil::setColor(rlutil::WHITE);

			showItem("       Categorias       ", 48, 11, y == 0);
			showItem("   Carrito de Compras   ", 48, 12, y == 1);
			showItem("        Ordenes         ", 48, 13, y == 2);
			showItem("    Generar ordenes     ", 48, 14, y == 3);
			showItem("  Ordenes relacionadas  ", 48, 15, y == 4);
			showItem("         Salir          ", 48, 16, y == 5);

			rlutil::locate(46, 11 + y);
			cout << (char)175 << endl;

			switch (rlutil::getkey())
			{
			case 14: //UP
				rlutil::locate(46, 11 + y);
				cout << " " << endl;
				if (y > 0)y--;
				break;
			case 15: //DOWN
				rlutil::locate(46, 11 + y);
				cout << " " << endl;
				if(y<5) y++;
				break;
			case 1: //ENTER
				switch (y)
				{
				case 0:
					break;
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					op = 0;
					break;
				}
				break;
			}
		}
	}

	int MenuInicio() {
		int op,y=0;
		rlutil::hidecursor();
		rlutil::cls();
		while(true){
			LogoTottus();
			rlutil::setColor(rlutil::WHITE);

			showItem("       Categorias       ", 48, 11, y == 0);
			showItem("   Carrito de Compras   ", 48, 12, y == 1);
			showItem("        Ordenes         ", 48, 13, y == 2);
			showItem("    Generar ordenes     ", 48, 14, y == 3);
			showItem("  Ordenes relacionadas  ", 48, 15, y == 4);
			showItem("       Creditos         ", 48, 16, y == 5);
			showItem("         Salir          ", 48, 17, y == 6);

			rlutil::locate(46, 11 + y);
			cout << (char)175 << endl;

			switch (rlutil::getkey())
			{
			case 14: //UP
				rlutil::locate(46, 11 + y);
				cout << " " << endl;
				if (y > 0)y--;
				break;
			case 15: //DOWN
				rlutil::locate(46, 11 + y);
				cout << " " << endl;
				if (y < 6) y++;
				break;
			case 1: //ENTER
				switch (y)
				{
				case 0:
					op = 1;
					break;
				case 1:
					op = 2;
					break;
				case 2:
					op = 3;
					break;
				case 3:
					op = 4;
					break;
				case 4:
					op = 5;
					break;
				case 5:
					op = 6;
					break;
				case 6:
					op = 7;
				}
				return op;
				break;
			}
		}
	}

	int MenuCategorias2() {
		int op, y = 0;
		rlutil::hidecursor();
		rlutil::cls();
		while (true) {
			LogoTottus();
			rlutil::setColor(rlutil::WHITE);

			rlutil::locate(48, 11);
			cout << "::::::::CATEGORIAS:::::::" << endl;
			showItem("       Tecnologia       ", 48, 12, y == 0);
			showItem("          Ropa          ", 48, 13, y == 1);
			showItem("        Comidas         ", 48, 14, y == 2);
			showItem("       Jugueteria       ", 48, 15, y == 3);
			showItem("    Rangos de precio    ", 48, 16, y == 4);
			showItem("         Salir          ", 48, 17, y == 5);

			rlutil::locate(46, 12 + y);
			cout << (char)175 << endl;

			switch (rlutil::getkey())
			{
			case 14: //UP
				rlutil::locate(46, 12 + y);
				cout << " " << endl;
				if (y > 0)y--;
				break;
			case 15: //DOWN
				rlutil::locate(46, 12 + y);
				cout << " " << endl;
				if (y < 5) y++;
				break;
			case 1: //ENTER
				switch (y)
				{
				case 0:
					op = 1;
					break;
				case 1:
					op = 2;
					break;
				case 2:
					op = 3;
					break;
				case 3:
					op = 4;
					break;
				case 4:
					op = 5;
					break;
				case 5:
					op = 6;
					break;
				}
				return op;
				break;
			}
		}
	}

	void MenuCategorias() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::CATEGORIAS:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "1) Tecnologia" << endl;
		cout << "2) Ropa" << endl;
		cout << "3) Comidas" << endl;
		cout << "4) Jugueteria" << endl;
		cout << "5) Rangos de precio" << endl;
		cout << "6) Salir" << endl;
	}

	void MenuTecnologia() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::TECNOLOGIA:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\nSeleccione producto para agregar al carrito:\n\n";
		for (int i = 0; i < vecTecnologia.size(); i++) {
			cout << i + 1 << ") " << vecTecnologia[i]->getCodigo() << "  " << vecTecnologia[i]->getNombre() << "  [Precio: S/" << vecTecnologia[i]->getPrecio() << "]" << endl;
		}
		cout << vecTecnologia.size() + 1 << ") Salir" << endl;
		cout << "\nIngrese una opcion: ";
	}

	void MenuRopa() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::ROPA:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\nSeleccione producto para agregar al carrito:\n\n";
		for (int i = 0; i < vecRopa.size(); i++) {
			cout << i + 1 << ") " << vecRopa[i]->getCodigo() << "  " << vecRopa[i]->getNombre() << "  [Precio: S/" << vecRopa[i]->getPrecio() << "]" << endl;
		}
		cout << vecRopa.size() + 1 << ") Salir" << endl;
		cout << "\nIngrese una opcion: ";
	}

	void MenuComidas() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::COMIDAS:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\nSeleccione producto para agregar al carrito:\n\n";
		for (int i = 0; i < vecComida.size(); i++) {
			cout << i + 1 << ") " << vecComida[i]->getCodigo() << "  " << vecComida[i]->getNombre() << "  [Precio: S/" << vecComida[i]->getPrecio() << "]" << endl;
		}
		cout << vecComida.size() + 1 << ") Salir" << endl;
		cout << "\nIngrese una opcion: ";
	}

	void MenuJugueteria() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::JUGUETERIA:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "\nSeleccione producto para agregar al carrito:\n\n";
		for (int i = 0; i < vecJugueteria.size(); i++) {
			cout << i + 1 << ") " << vecJugueteria[i]->getCodigo() << "  " << vecJugueteria[i]->getNombre() << "  [Precio: S/" << vecJugueteria[i]->getPrecio() << "]" << endl;
		}
		cout << vecJugueteria.size() + 1 << ") Salir" << endl;
		cout << "\nIngrese una opcion: ";
	}


	void MenuCarritodeCompras() {
		SetConsoleTextAttribute(hConsole, 10);
		cout << "::::::::CARRITO DE COMPRAS:::::::" << endl;
		SetConsoleTextAttribute(hConsole, 7);
		cout << "1) Ver Carrito de Compras" << endl;
		cout << "2) Ver Carrito de Compras Ordenado por precio" << endl;
		cout << "3) Ver carrito de Compras Ordenado por codigo" << endl;
		cout << "4) Buscar producto por nombre" << endl;
		cout << "5) Buscar producto por codigo" << endl;
		cout << "6) Eliminar Producto" << endl;
		cout << "7) Pagar" << endl;
		cout << "8) Volver" << endl;
	}

	int MenuCarritodeCompras2() {
		int op, y = 0;
		rlutil::hidecursor();
		rlutil::cls();
		while (true) {
			LogoTottus();
			rlutil::setColor(rlutil::WHITE);

			rlutil::locate(44, 11);
			cout <<  "::::::::CARRITO DE COMPRAS::::::::" << endl;
			showItem("      Ver Carrito de Compras      ", 44, 13, y == 0);
			showItem("        Ordenar por precio        ", 44, 14, y == 1);
			showItem("        Ordenar por codigo        ", 44, 15, y == 2);
			showItem("    Buscar producto por nombre    ", 44, 16, y == 3);
			showItem("    Buscar producto por codigo    ", 44, 17, y == 4);
			showItem("        Eliminar Producto         ", 44, 18, y == 5);
			showItem("            Ir a Pagar            ", 44, 19, y == 6);
			showItem("             Volver               ", 44, 20, y == 7);

			rlutil::locate(42, 13 + y);
			cout << (char)175 << endl;

			switch (rlutil::getkey())
			{
			case 14: //UP
				rlutil::locate(42, 13 + y);
				cout << " " << endl;
				if (y > 0)y--;
				break;
			case 15: //DOWN
				rlutil::locate(42, 13 + y);
				cout << " " << endl;
				if (y < 7) y++;
				break;
			case 1: //ENTER
				switch (y)
				{
				case 0:
					op = 1;
					break;
				case 1:
					op = 2;
					break;
				case 2:
					op = 3;
					break;
				case 3:
					op = 4;
					break;
				case 4:
					op = 5;
					break;
				case 5:
					op = 6;
					break;
				case 6:
					op = 7;
					break;
				case 7:
					op = 8;
					break;
				}
				return op;
				break;
			}
		}
	}

	void LogoTottus() {     //TOTTUS
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		rlutil::setColor(rlutil::COLOR::LIGHTGREEN);
		Console::SetCursorPosition(38,2);
		cout << ":::::: :::::: :::::: :::::: ::  :: ::::::";
		Console::SetCursorPosition(38,3);
		cout << "  ::   ::  ::   ::     ::   ::  :: ::    ";
		Console::SetCursorPosition(38,4);
		cout << "  ::   ::  ::   ::     ::   ::  :: ::::::";
		Console::SetCursorPosition(38,5);
		cout << "  ::   ::  ::   ::     ::   ::  ::     ::";
		Console::SetCursorPosition(38,6);
		cout << "  ::   ::::::   ::     ::   :::::: ::::::";
	}

	void Creditos() {
		rlutil::cls();
		rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
		//rlutil::setColor(rlutil::COLOR::YELLOW);
		Console::ForegroundColor = ConsoleColor::Green;
		rlutil::locate(41,5);
		cout << char(201);
		rlutil::locate(41,6);
		cout << char(186);
		rlutil::locate(41,7);
		cout << char(200);

		for (int i = 42; i <= 84; i++) {
			rlutil::locate(i, 5);
			cout << char(205);
			rlutil::locate(i, 7);
			cout << char(205);
			Sleep(50);
		}

		rlutil::locate(85, 5);
		cout << char(187);
		rlutil::locate(85, 6);
		cout << char(186);
		rlutil::locate(85, 7);
		cout << char(188);

		string credito = " CREDITOS DEL PROYECTO ";
		int longitud = credito.length();
		int centro = (63-(longitud/2));


		for (int i = 42; i <= centro; i++) {
			int color = rand() % 9;
			Console::ForegroundColor = ConsoleColor::White;
			rlutil::locate(i,6);
			cout << credito;
			Sleep(100);
		}

		//para los nombres
		Console::ForegroundColor = ConsoleColor::White;
		rlutil::locate(49, 12);
		cout << char(201);
		rlutil::locate(49, 13);
		cout << char(186);
		rlutil::locate(49, 14);
		cout << char(186);
		rlutil::locate(49, 15);
		cout << char(186);
		rlutil::locate(49, 16);
		cout << char(186);
		rlutil::locate(49, 17);
		cout << char(186);
		rlutil::locate(49, 18);
		cout << char(186);
		rlutil::locate(49, 19);
		cout << char(186);
		rlutil::locate(49, 20);
		cout << char(200);

		//Joseph Huamani
		//Jeremy Quispe
		//Hernan Morales
		for (int i = 50; i <= 76; i++) {
			rlutil::locate(i, 12);
			cout << char(205);
			rlutil::locate(i, 20);
			cout << char(205);
			Sleep(50);
		}

		rlutil::locate(77, 12);
		cout << char(187);
		rlutil::locate(77, 13);
		cout << char(186);
		rlutil::locate(77, 14);
		cout << char(186);
		rlutil::locate(77, 15);
		cout << char(186);
		rlutil::locate(77, 16);
		cout << char(186);
		rlutil::locate(77, 17);
		cout << char(186);
		rlutil::locate(77, 18);
		cout << char(186);
		rlutil::locate(77, 19);
		cout << char(186);
		rlutil::locate(77, 20);
		cout << char(188);

		string joseph = " JOSEPH HUAMANI ";
		string jeremy = " JEREMY QUISPE  ";
		string hernan = " HERNAN MORALES ";

		int longitud2 = joseph.length();
		int centro2 = 55;


		for (int i = 50; i <= centro2; i++) {
			//int color = rand() % 9;
			Console::ForegroundColor = ConsoleColor::White;
			rlutil::locate(i, 14);
			cout << joseph;
			Sleep(100);
		}

		for (int i = 50; i <= centro2; i++) {
			//int color = rand() % 9;
			Console::ForegroundColor = ConsoleColor::White;
			rlutil::locate(i, 16);
			cout << jeremy;
			Sleep(100);
		}

		for (int i = 50; i <= centro2; i++) {
			//int color = rand() % 9;
			Console::ForegroundColor = ConsoleColor::White;
			rlutil::locate(i, 18);
			cout << hernan;
			Sleep(100);
		}

		Console::ForegroundColor = ConsoleColor::Magenta;
		rlutil::locate(22, 12);
		cout << " ,-.______________,=========,";
		rlutil::locate(74, 12);
		cout << " ,=========,______________.-, ";
		Sleep(50);


		rlutil::locate(22, 13);
		cout << "[|  )_____________)#######((_";
		rlutil::locate(74, 13);
		cout << " _))#######(_____________(  |]";
		Sleep(50);


		rlutil::locate(22, 14);
		cout << " /===============.-.___,--* _\\";
		rlutil::locate(73, 14);
		cout << " /_ *--,___.-.===============\\";
		Sleep(50);


		rlutil::locate(22, 15);
		cout << "* - ._, __, __[JW]____\\########/ "; //
		rlutil::locate(71, 15);
		cout << " \\########/____[JW]__ ,__ ,_. - *";
		Sleep(50);


		rlutil::locate(22, 16);
		cout << "         \\ (  )) )####O##(    "; //
		rlutil::locate(76, 16);
		cout << "  )##O####( ((  ) /         ";
		Sleep(50);


		rlutil::locate(22, 17);
		cout << "           \\ \\___/,.#######\\";//
		rlutil::locate(76, 17);
		cout << "/#######.,\\___/ /           ";
		Sleep(50);


		rlutil::locate(22, 18);
		cout << "            `====*  \\#######\\";//
		rlutil::locate(75, 18);
		cout << "/#######/  *====`            ";
		Sleep(50);


		rlutil::locate(22, 19);
		cout << "                     \\#######\\";//
		rlutil::locate(74, 19);
		cout << "/#######/                     ";
		Sleep(50);


		rlutil::locate(22, 20);
		cout << "                      )##O####|";//
		rlutil::locate(73, 20);
		cout << "|####0##(                      ";
		Sleep(50);


		rlutil::locate(22, 21);
		cout << "                      )####__,*";//
		rlutil::locate(73, 21);
		cout << "*,__####(                      ";
		Sleep(50);


		rlutil::locate(22, 22);
		cout << "                      `--**";//
		rlutil::locate(77, 22);
		cout << "**--`                      ";
		Sleep(50);
	

	}



	
};