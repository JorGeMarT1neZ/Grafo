#include "Grafo.h"

int main(int argc, char** argv) 
{
	Grafo G; 
    G.InsertarNodo("A");
    G.InsertarNodo("B"); 
    G.InsertarNodo("C");  
    G.InsertarNodo("D");
    G.InsertarNodo("E"); 
    G.InsertarNodo("F"); 
    G.InsertarNodo("G");
    G.InsertarNodo("H"); 
    G.InsertarNodo("I");  
    G.InsertarNodo("J");
    G.InsertarNodo("K"); 
    G.InsertarNodo("L"); 
    G.InsertarArista("A","B",1); 
    G.InsertarArista("A","C",2);
    G.InsertarArista("A","D",3);
    G.InsertarArista("A","E",4);
    G.InsertarArista("A","F",5);
    G.InsertarArista("A","G",1);
    G.InsertarArista("A","H",1);
    G.InsertarArista("A","I",1);
    G.InsertarArista("A","J",1);
    G.InsertarArista("A","F",1);
    G.InsertarArista("B","F",1);
    G.InsertarArista("C","A",1);
    G.InsertarArista("D","G",1);
    G.InsertarArista("E","I",1);
    G.InsertarArista("F","L",1);
    G.InsertarArista("G","A",1);
    G.InsertarArista("H","A",1);
    G.InsertarArista("I","E",1);
    G.InsertarArista("I","F",1);
    G.InsertarArista("I","G",1);
    G.InsertarArista("I","H",1);
    G.InsertarArista("I","I",1);
    G.InsertarArista("J","L",1);
    G.InsertarArista("J","A",1);
    G.InsertarArista("J","A",1);
    G.InsertarArista("J","E",1);
    G.InsertarArista("J","F",1);
    G.InsertarArista("B","A",1);
    G.InsertarArista("D","A",1);
    G.InsertarArista("E","A",1);
    G.InsertarArista("F","A",1);
    G.InsertarArista("C","B",1);
    G.InsertarArista("D","B",1);
    G.InsertarArista("G","B",1);
    G.InsertarArista("L","B",1);
    G.VerNodos(); 
    G.MostrarGrafo();
    G.Imprimir(); 
	menu(G); 

}
