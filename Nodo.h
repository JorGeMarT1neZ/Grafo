#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <fstream>
#include "Arista.h"
using std::cout ; 
using std::cin ; 
using std::endl ; 
using std::string ; 
using std::ifstream ; 
using std::ofstream ;
class Arista ;

class Nodo
{
	private:
		string Nom; 
		Nodo *SigNodo; 
		Arista *AristaPtr;
	public:
		Nodo():Nom("NuevoGrafo"),SigNodo(NULL),AristaPtr(NULL){;}
		Nodo(string n):Nom(n),SigNodo(NULL),AristaPtr(NULL){;}
	   ~Nodo(){;}
	    void SetNom(string n){Nom = n;}
	    string GetNom()const{return Nom;}
	    void SetSigNodo(Nodo *S){SigNodo = S;}
	    Nodo *GetSigNodo()const{return SigNodo;}
	    void SetAristaPtr(Arista *A){AristaPtr = A;}
	    Arista *GetAristaPtr()const{return AristaPtr;}
	    void Mostrar(); 
	protected:
};
#endif
