#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"

class Grafo
{
	private: 
	    Nodo *Inicio ; 
	public:
		Grafo():Inicio(NULL){;}
		void SetInicio(Nodo *I){Inicio = I;}
		Nodo * GetInicio()const{return Inicio;}
		void Imprimir(); 
		void InsertarNodo(string); 
		void VerNodos(); 
		void InsertarArista(Nodo *,Nodo *,int); // sobrecarga de metodos 
		void InsertarArista(string,string,int); 
		Nodo * ValidarNodo(string); 
		void MostrarGrafo(); 
		bool ValidarConexion(Nodo *,Nodo *); 
		void EliminarNodo(string); 
		void EliminarArista(string,string); 
		void LeerNodos(string); 
		void LeerAristas(string); 
		void GuardarGrafo(string);
		void GuardarNodos(string);
	protected:
};
void menu(Grafo &); 
#endif

