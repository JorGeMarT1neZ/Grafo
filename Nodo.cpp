#include "Nodo.h"

void Nodo::Mostrar()
{
	cout<<this<<"="<<"Nombre--"<<GetNom()<<"--Arista--"<<GetAristaPtr()<<endl; 
	cout <<"Sig Nodo : " <<GetSigNodo()<<endl ; 
	cout <<"-----------------------------------------------------"<<endl; 
}
