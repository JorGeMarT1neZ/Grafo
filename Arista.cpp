#include "Arista.h"

void Arista::Mostrar()
{
	cout <<"|" << GetPeso() << "-" << GetDestino()->GetNom()<<"|--";  
}
