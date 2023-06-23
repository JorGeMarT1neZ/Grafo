#ifndef ARISTA_H
#define ARISTA_H
#include "Nodo.h"
class Nodo; 
class Arista
{
	private:
		int Peso; 
		Nodo *Destino; 
		Arista *SigArista; 
	public:
		Arista():Peso(0),Destino(NULL),SigArista(NULL){;}
		Arista(Nodo *Des,int Pe):Peso(Pe),Destino(Des),SigArista(NULL){;}
	   ~Arista(){;}
	    void SetPeso(int P ){Peso = P;}
	    int GetPeso()const{return Peso;}
	    void SetDestino(Nodo *D){Destino = D;}
	    Nodo *GetDestino()const{return Destino;}
	    void SetSigArista(Arista *S){SigArista = S;}
	    Arista *GetSigArista()const{return SigArista;}
	    void Mostrar(); 
	protected:
};
#endif
