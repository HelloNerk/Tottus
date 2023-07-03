#pragma once
#include <vector>
using namespace std;

//Ordenes nombre del usuario y mostrar productos en forma de grafo


template<class T, T vacio = -1>
class CGrafo {
private:
	class CArco {
	public:
		T info;
		int v; //indice del vertice de llegada
		CArco(int vLlegada) {
			info = vacio;
			v = vLlegada;
		}
	};
	class CVertice {
	public:
		T info;
		vector<CArco*>* ady; //Lista de adyacencia
		CVertice() {
			info = vacio;
			ady = new vector<CArco*>();
		}
	};
	//Lista de v�rtices
	vector<CVertice*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice* vert = new CVertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1;
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) {
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) {
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) {
		CVertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		CArco* arc = new CArco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1;
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	void eliminarArcos(int v) {
		CVertice* ver = vertices->at(v);
		for (int i = 0; i < ver->ady->size(); i++) {
			delete ver->ady->at(i);
		}
		ver->ady->clear();
	}

	void eliminarVertice(int v) {
		CVertice* ver = vertices->at(v);
		for (int i = 0; i < ver->ady->size(); i++) {
			delete ver->ady->at(i);
		}
		ver->ady->clear();
		delete ver;
		vertices->erase(vertices->begin() + v);
	}

	T obtenerArco(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int v, int apos) {
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}
};
