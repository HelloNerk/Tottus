#pragma once
#include "Cuenta.h"
#include "Pila.h"
#include "Lista.h"
#include <string>
#include "Producto.h"
#include "ProductoTecnologia.h"
#include "ProductoComida.h"
#include "ProductoRopa.h"
#include "ProductoJugueteria.h"
#include "Cola.h"
#include "Arbol.h"
#include "Ordenes.h"
#include "AVL.h"
#include "Grafos.h"
#include "rlutil.h"
#include <fstream>
#include <sstream>
#include <vector>
#include "HashTablaA.h"



class Controller {
private:
	//Pila<Cuenta*>* pilacuentas;
	//Pila<Producto*> pilaproductos;
	vector<Producto*> vecProductos;
	Lista<Cuenta*>* listacuentas;
	Arbol<string> arbolProductos;
	Cola<Ordenes*>* colaOrdenes;
	AVL<Producto*> avl;
	vector<Producto*> productosEnRango;
	vector<Ordenes*> vecOrdenes;
	HashTablaA hashproducto = HashTablaA();
	CGrafo<int>* grafoorden;
	int cant;
	int cantOrder;
	string Name;
	string Fullname;
	string dni;
	string email;
	string direccion;
	long long telefono;
	long long tarjeta;
	int cvv;
	string vencimiento;
	int contador;

public:
	Controller() {
		//pilacuentas = new Pila<Cuenta*>();
		//pilaproductos = new Pila<Producto*>();
		colaOrdenes = new Cola<Ordenes*>();
		listacuentas = new Lista<Cuenta*>();
		avl = AVL<Producto*>();
		int cant;
		cantOrder = 0;
	}

	//void agregarCuenta(string _name, string _fullname, string _dni, string _email, string _direccion, long long _telefono, long long _tarjeta, int _cvv, string _vencimiento) {
	//	pilacuentas->push(new Cuenta(_name,_fullname,_dni,_email,_direccion,_telefono,_tarjeta,_cvv,_vencimiento));
	//}

	void agregarCuenta2(Cuenta* c) {
		listacuentas->push(c);
	}


	//void imprimirCuentas() {
	//	pilacuentas->print([](Cuenta* u) {u->Datos(); });
	//}

	void imprimirCuentas2() {
		listacuentas->print([](Cuenta* u) {u->Datos(); });
	}

	int agregar_carrito_compras() {
		int n;
		do {
			cout << "Desea agregar este producto al carrito? Si[1], No[0]: ";
			cin >> n;
		} while (n < 0 || n>1);
		return n;
	}

	void agregarProducto(int cat, int n) {
		if (agregar_carrito_compras() == 1) {
			string nombreProducto;
			string marca;
			double precio;
			int codigo;

			ifstream archivoProductos;

			if (cat == 1) {
				archivoProductos.open("productos_tecnologia.txt");
			}
			else if (cat == 2) {
				archivoProductos.open("productos_ropa.txt");
			}
			else if (cat == 3) {
				archivoProductos.open("productos_comida.txt");
			}
			else if (cat == 4) {
				archivoProductos.open("productos_jugueteria.txt");
			}

			if (archivoProductos.is_open()) {
				string linea;
				int contador = 1;

				while (getline(archivoProductos, linea)) {
					if (contador == n) {
						stringstream ss(linea);
						getline(ss, nombreProducto, ',');
						getline(ss, marca, ',');
						ss >> precio;
						ss.ignore();
						ss >> codigo;
						break;
					}

					contador++;
				}

				archivoProductos.close();
			}
			else {
				cout << "No se pudo abrir el archivo de productos." << endl;
				return;
			}

			Producto* nuevoProducto = new Producto(nombreProducto, marca, precio, codigo);
			vecProductos.push_back(nuevoProducto);
			arbolProductos.insertar(nombreProducto);
			hashproducto.insert(HashEntidad(codigo, nombreProducto));
			avl.insertar(nuevoProducto);
		}
		cant++;
	}

	void sumaProductoTotal(vector<Producto*> vec) {
		float precioTotal = 0;
		for (int i = 0; i < vec.size(); i++) {
			precioTotal = precioTotal + vec[i]->getPrecio();
		}
		cout << "TOTAL A PAGAR: S/" << precioTotal << endl;
	}

	void imprimirProductosRecursivo(int i) {
		if (i == vecProductos.size()) { // Caso base: se ha llegado al final del vector
			return;
		}
		vecProductos[i]->DatosProducto(); // Imprimir los datos del producto actual
		cout << endl;
		imprimirProductosRecursivo(i + 1); // Caso recursivo: imprimir el siguiente producto
	}

	void imprimirProductos() {
		system("cls");
		imprimirProductosRecursivo(0); // Empezar a imprimir desde el primer producto (índice 0)
		sumaProductoTotal(vecProductos);
	}

	void eliminarProductoRecursivo() {
		int pos;
		cout << "Ingrese la posicion del producto que desea eliminar: "; cin >> pos;
		// Restar 1 al valor de pos para utilizar un índice base 0
		pos--;
		if (pos < 0 || pos >= vecProductos.size()) {
			cout << "Posicion invalida" << endl;
			eliminarProductoRecursivo(); // Llamada recursiva: volver a pedir la posición del producto a eliminar
			return;
		}
		vecProductos.erase(vecProductos.begin() + pos);
		cant--;
		cout << "Eliminando producto..." << endl;
		_sleep(2500);
		cout << "Producto eliminado con exito!" << endl;
	}


	void eliminarProducto() {
		system("cls");
		eliminarProductoRecursivo(); // Llamada inicial a la función recursiva
	}

	int contarDigitos(long long n) {
		if (n == 0) { // Caso base: el número es cero
			return 0;
		}
		else { // Caso recursivo: quitar el último dígito y llamar a la función de nuevo
			return 1 + contarDigitos(n / 10);
		}
	}

	void pagarProductos() {
		rlutil::setColor(rlutil::COLOR::WHITE);
		rlutil::locate(45, 11);
		cout << "Complete los siguientes datos: \n\n";
		rlutil::locate(45, 13);
		cout << "Nombre: "; cin >> Name;
		rlutil::locate(45, 14);
		cout << "Apellido: "; cin >> Fullname;
		rlutil::locate(45, 15);
		cout << "DNI: "; cin >> dni;
		rlutil::locate(45, 16);
		cout << "Email: "; cin >> email;
		rlutil::locate(45, 17);
		cout << "Direccion: "; 
		cin.ignore();
		getline(cin, direccion);
		do {
			rlutil::locate(45, 18);
			cout << "                                                                             ";
			rlutil::locate(45, 18);
			cout << "Telefono: ";
			cin >> telefono;
			contador = contarDigitos(telefono);
		} while (contador != 9);
		do {
			rlutil::locate(45, 19);
			cout << "                                                                             ";
			rlutil::locate(45,19);
			cout << "Tarjeta (XXXX-XXXX-XXXX-XXXX): "; cin >> tarjeta;
			contador = contarDigitos(tarjeta);
		} while (contador != 16);
		do {
			rlutil::locate(45, 20);
			cout << "                                                                             ";
			rlutil::locate(45, 20);
			cout << "CVV: "; cin >> cvv;
			contador = contarDigitos(cvv);
		} while (contador != 3);
		rlutil::locate(45, 21);
		cout << "F. Vencimiento: "; cin >> vencimiento;

		//agregarCuenta1(Name, Fullname, dni, email, direccion, telefono, tarjeta, cvv, vencimiento);
		Cuenta* cuentanueva = new Cuenta(Name, Fullname, dni, email, direccion, telefono, tarjeta, cvv, vencimiento);
		agregarCuenta2(cuentanueva);
		_sleep(200);
		rlutil::locate(45, 23);
		cout << "Verificando datos...\n";
		_sleep(3000);
		rlutil::locate(45, 24);
		cout << "Pago realizado!";
		cantOrder++;
		Ordenes* orden = new Ordenes(cuentanueva, vecProductos, cantOrder);
		colaOrdenes->enqueue(orden);
		vecOrdenes.push_back(orden);
	}

	void imprimirOrdenes() {
		colaOrdenes->print([](Ordenes* u) {u->mostrarPedido(); });
	}

	void imprimirOrdenesGrafo() {
		colaOrdenes->print([](Ordenes* u) {u->mostrarOrdenName(); });
	}

	void buscarProductoPorNombre() {
		system("cls");
		cout << "Ingrese el nombre del producto a buscar: ";
		string productoBuscado;
		cin.ignore();
		getline(cin, productoBuscado);

		int indice = arbolProductos.busquedaBinaria(productoBuscado);
		if (indice != -1) {
			cout << "Buscando producto..." << endl;
			_sleep(1500);
			cout << "El producto esta en el carrito de compras." << endl;
		}
		else {
			cout << "Buscando producto..." << endl;
			_sleep(1500);
			cout << "El producto no esta en el carrito de compras." << endl;
		}
	}


	void buscarProductoPorCodigo() {
		int cod;
		system("cls");
		cout << "Ingrese el codigo del producto a buscar: ";
		cin >> cod;
		hashproducto.buscar(cod);
	}

	void buscarProductoPorPrecio() {
		double precioMin, precioMax;
		cout << "Ingrese el rango de precios (precio minimo): ";
		cin >> precioMin;
		cout << "Ingrese el rango de precios (precio maximo): ";
		cin >> precioMax;

		string categoria;
		cout << "Ingrese la categoria de productos (jugueteria, comida, ropa, tecnologia): ";
		cin >> categoria;

		string nombreArchivo = "productos_" + categoria + ".txt";
		ifstream archivoProductos(nombreArchivo);
		if (!archivoProductos.is_open()) {
			cout << "No se pudo abrir el archivo de productos." << endl;
			return;
		}

		string linea;
		int productosEncontrados = 0;
		vector<Producto*> productosEnLista;

		while (getline(archivoProductos, linea)) {
			stringstream ss(linea);
			string nombreProducto;
			string marca;
			double precio;
			int codigo;

			getline(ss, nombreProducto, ',');
			getline(ss, marca, ',');
			ss >> precio;
			ss.ignore();
			ss >> codigo;

			if (precio >= precioMin && precio <= precioMax) {
				Producto* nuevoProducto = new Producto(nombreProducto, marca, precio, codigo);
				productosEnLista.push_back(nuevoProducto);
				productosEncontrados++;
			}
		}

		archivoProductos.close();

		if (productosEncontrados == 0) {
			cout << "No se encontraron productos dentro del rango de precios especificado." << endl;
			return;
		}

		cout << "Productos encontrados:" << endl << endl << endl;
		for (int i = 0; i < productosEnLista.size(); i++) {
			cout << i + 1 << ") ";
			productosEnLista[i]->mostrar_nombre_codigo_precio();
			cout << endl;
		}

		cout << "Seleccione el numero de producto que desea agregar al carrito: ";
		int numeroProducto;
		cin >> numeroProducto;

		if (numeroProducto >= 1 && numeroProducto <= productosEnLista.size()) {
			Producto* productoSeleccionado = productosEnLista[numeroProducto - 1];

			if (agregar_carrito_compras() == 1) {
				vecProductos.push_back(productoSeleccionado);
				arbolProductos.insertar(productoSeleccionado->getNombre());
				hashproducto.insert(HashEntidad(productoSeleccionado->getCodigo(), productoSeleccionado->getNombre()));
				avl.insertar(productoSeleccionado);
				cant++;
				cout << "Producto agregado al carrito correctamente." << endl;
			}
			else {
				cout << "Producto no agregado al carrito." << endl;
			}
		}
		else {
			cout << "Número de producto inválido. No se agregó ningún producto al carrito." << endl;
		}
	}

	void datasetOrdenes() {
		ifstream archivoOrdenes("OrdenesDataset.txt");
		if (!archivoOrdenes.is_open()) {
			cout << "No se pudo abrir el archivo de órdenes." << endl;
			return;
		}

		string linea;
		//int numOrden = 1;
		while (getline(archivoOrdenes, linea)) {
			stringstream ss(linea);
			string nombre;
			string apellido;
			string dni;
			string distrito;
			string nombreProducto;
			int codigoProducto;
			double precio;

			getline(ss, nombre, ',');
			getline(ss, apellido, ',');
			getline(ss, dni, ',');
			getline(ss, distrito, ',');
			getline(ss, nombreProducto, ',');
			ss >> codigoProducto;
			ss.ignore();
			ss >> precio;


			Cuenta* cuenta = new Cuenta(nombre, apellido, dni, "", distrito, 0, 0, 0, "");

			Producto* producto = new Producto(nombreProducto, "", precio, codigoProducto);

			vector<Producto*> vecProductos;
			vecProductos.push_back(producto);
			cantOrder++;
			Ordenes* orden = new Ordenes(cuenta, vecProductos, cantOrder);

			
			colaOrdenes->enqueue(orden);
			vecOrdenes.push_back(orden);
			//numOrden++;
		}

		archivoOrdenes.close();

		cout << "Las ordenes se han cargado correctamente desde el archivo." << endl;
	}


	void RadixSortporPrecio() {

		vector<Producto*> vecProductosCopia = vecProductos;
		if (vecProductosCopia.size() <= 0) {
			cout << "Carrito Vacio" << endl;
			return;
		}

		double maxPrice = vecProductosCopia[0]->getPrecio();
		for (const auto& producto : vecProductosCopia) {
			if (producto->getPrecio() > maxPrice) {
				maxPrice = producto->getPrecio();
			}
		}

		for (double exp = 1; maxPrice / exp > 0; exp *= 10) {
			vector<Producto*> output(vecProductosCopia.size());
			vector<int> count(10, 0);

			for (const auto& producto : vecProductosCopia) {
				int digit = static_cast<int>(static_cast<int>(producto->getPrecio() / exp) % 10);
				count[digit]++;
			}
			for (int i = 1; i < 10; i++) {
				count[i] += count[i - 1];
			}

			for (int i = vecProductosCopia.size() - 1; i >= 0; i--) {
				int digit = static_cast<int>(vecProductosCopia[i]->getPrecio() / exp) % 10;
				output[count[digit] - 1] = vecProductosCopia[i];
				count[digit]--;
			}

			for (size_t i = 0; i < vecProductosCopia.size(); i++) {
				vecProductosCopia[i] = output[i];
			}
		}

		for (const auto& producto : vecProductosCopia) {
			producto->DatosProducto();
			cout << endl;
		}
		sumaProductoTotal(vecProductosCopia);
	}

	void Heapify(vector<Producto*>& arr, int n, int i) {
		int largest = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;

		if (l < n && arr[l]->getCodigo() > arr[largest]->getCodigo())
			largest = l;

		if (r < n && arr[r]->getCodigo() > arr[largest]->getCodigo())
			largest = r;

		if (largest != i) {
			swap(arr[i], arr[largest]);
			Heapify(arr, n, largest);
		}
	}

	void HeapSortporCodigo() {
		vector<Producto*> vecProductosCopia = vecProductos;
		if (vecProductosCopia.size() <= 0) {
			cout << "Carrito Vacio";
			return;
		}
		else if (vecProductosCopia.size() > 0) {
			int n = vecProductosCopia.size();

			// Construir el montículo inicial
			for (int i = n / 2 - 1; i >= 0; i--)
				Heapify(vecProductosCopia, n, i);

			// Extraer elementos del montículo uno por uno
			for (int i = n - 1; i > 0; i--) {
				swap(vecProductosCopia[0], vecProductosCopia[i]);
				Heapify(vecProductosCopia, i, 0);
			}

			// Mostrar los productos ordenados por código
			for (int i = 0; i < vecProductosCopia.size(); i++) {
				vecProductosCopia[i]->DatosProducto();
				cout << endl;
			}

			sumaProductoTotal(vecProductosCopia);
		}
	}


	void clearProductos() {
		while (!vecProductos.empty()) {
			vecProductos.erase(vecProductos.begin());
			cant--;
		}
	}

	void GrafosOrdenes() {
		system("cls");
		cout << "Clientes relacionados por distrito:" << endl;

		grafoorden= new CGrafo<int>();
		
		for (int i = 0; i < vecOrdenes.size(); i++) {
			cout << i << ": ";
			vecOrdenes[i]->getNombre();
			cout << "--> " << vecOrdenes[i]->distrito() << endl;
			grafoorden->adicionarVertice(i); //indice i
		}

		for (int i = 0; i < vecOrdenes.size(); i++) {
			int cantAr = 0; 
			for (int j = 0; j < cantOrder; j++) {
				if (i!=j && vecOrdenes[i]->distrito() == vecOrdenes[j]->distrito()) {
					grafoorden->adicionarArco(i, j);  //vertice de partida y vertice de llegada
					grafoorden->modificarArco(i, cantAr, j);
					cantAr++;
				}
			}
		}

		cout << "\n\n";
		for (int i = 0; i < grafoorden->cantidadVertices(); ++i) {
			cout << "Cliente Index " << grafoorden->obtenerVertice(i) << ": ";
			for (int j = 0; j < grafoorden->cantidadArcos(i); j++) {
				cout << grafoorden->obtenerArco(i, j) << " --> ";
			}
			cout << "nullptr";
			cout << endl;
		}

		delete grafoorden;
	}
};