#include "Grafo.h"

void Grafo::Imprimir()
{
	if(!GetInicio())
	{
		cout << "\tEl Grafo Apunta a : " << GetInicio() << endl;
	}
	else
	{
		cout << "\tEl Grafo Apunta a : " << GetInicio() <<" -- "<< GetInicio()->GetNom() << endl;
	}
}
void Grafo::InsertarNodo(string S)
{
	Nodo * Nuevo = new Nodo(S);
	if(!GetInicio())
	{
		SetInicio(Nuevo); 
	}
	else
	{
		Nodo * Aux = GetInicio() ; 
		while(Aux->GetSigNodo())
		{
			Aux = Aux->GetSigNodo();  
		}
		Aux->SetSigNodo(Nuevo); 
	}
} 
void Grafo::VerNodos()
{
	if(!GetInicio())
	{
		cout << "\tGrafo Vacio " << endl ; 
	}
	else
	{
		Nodo *Aux(Inicio); 
		while(Aux)
		{
			Aux->Mostrar(); 
 			Aux = Aux->GetSigNodo();  
		}
	}
} 
Nodo *Grafo::ValidarNodo(string S)
{
	if(!GetInicio())
	{
		cout << "\tGrafo Vacio " << endl ;
		return 0 ;  
	}
	else
	{
		Nodo * Aux(Inicio); 
	    while(Aux)
	    {
		    if(Aux->GetNom() == S)break; 
		    Aux = Aux->GetSigNodo();  
	    }
	    if(!Aux)
		{
			cout << "\t Nodo |" << S << "| No Existe" << endl ;  
		}
	    return Aux;
	}
}
void Grafo::InsertarArista(Nodo *Ori,Nodo *Des,int pe)
{
	Nodo * Aux(Inicio);
	Arista * NuevaArista = new Arista(Des,pe); 
	while(Aux != Ori)
	{
		Aux = Aux->GetSigNodo();  
	}
	if(!Aux->GetAristaPtr())
	{
		Aux->SetAristaPtr(NuevaArista); 
	}
	else
	{
		Arista * temp = Aux->GetAristaPtr();
		while(temp->GetSigArista())
		{
			temp = temp->GetSigArista(); 
		} 
		temp->SetSigArista(NuevaArista); 
	}
}
void Grafo::InsertarArista(string Origen,string Destino,int Pe)
{
	Nodo *Ori = ValidarNodo(Origen); 
	Nodo *Des = ValidarNodo(Destino);
	if(!Ori && !Des)
	{
		cout <<"\tLos Nodos No Existen" << endl; 
	}
	else if(!Ori || !Des)
	{
		cout << "\tOrigen O Destino Invalidos " << endl ; 
	}
	else
	{
		InsertarArista(Ori,Des,Pe); 
	}
}
void Grafo::MostrarGrafo()
{
	if(!GetInicio())
	{
		cout << "\tGrafo Vacio " << endl ; 
	}
	else
	{
		Nodo * Aux(Inicio);
		while(Aux)
		{
			cout <<"\t"<< Aux->GetNom()<<"---";
			Arista * temp = Aux->GetAristaPtr();
			while(temp)
			{
				temp->Mostrar(); 
				temp = temp->GetSigArista(); 
			}
			cout<<endl; 
			Aux = Aux->GetSigNodo();  
		}
	}
} 
bool Grafo::ValidarConexion(Nodo *Ori,Nodo *Des)
{
	if(!Ori && !Des)
	{
		cout <<"\tLos Nodos No Existen" << endl; 
		return false;
	}
	else if(!Ori || !Des)
	{
		//cout << "\tOrigen O Destino Invalidos " << endl ; 
		return false;
	}
	else
	{
		Nodo * Aux(Inicio);
	    while(Aux != Ori)
	    {
		    Aux = Aux->GetSigNodo();  
	    }
	    if(!Aux->GetAristaPtr())
		{
			cout << "\tNodo Sin Aristas" << endl; 
			return false;	
		}
		else
		{
			Arista * temp = Aux->GetAristaPtr();
			bool band = 0 ;  
			while(temp && !band)
			{
				band = (temp->GetDestino() == Des)?1:0; 
				temp = temp->GetSigArista(); 
			}
			if(band)
			{
				return true;	
			}
			else
			{
				cout << "\tLa Conexion No Existe"<<endl;
				return false;	 
			}
		}
	}
}
void Grafo::EliminarArista(string Origen,string Destino)
{
	Nodo *Ori = ValidarNodo(Origen); 
	Nodo *Des = ValidarNodo(Destino);
	if(ValidarConexion(Ori,Des))
	{
		Nodo * Aux(Inicio);
	    while(Aux != Ori)
	    {
		    Aux = Aux->GetSigNodo();  
	    }
	    Arista * tempSig = Aux->GetAristaPtr() , *temp = NULL ; 
	    while(tempSig->GetDestino()!= Des)
		{
			temp = tempSig;  
		    tempSig = tempSig->GetSigArista();
		} 
		if(!temp)
		{
			Aux->SetAristaPtr(tempSig->GetSigArista()); 
			tempSig->SetSigArista(NULL); 
			delete tempSig; 
		}
		else
		{
			temp->SetSigArista(tempSig->GetSigArista()); 
			tempSig->SetSigArista(NULL); 
			delete tempSig; 
		}
	}
}
void Grafo::EliminarNodo(string  S)
{
	Nodo * Vertice = ValidarNodo(S);
	if(!Vertice)
	{
		cout <<"\tEl Nodo, No Existe" << endl; 
	}
	else
	{
		Nodo * Aux(Inicio);
		Arista *Arco = NULL;
		while(Aux)
		{
			Arco = Aux->GetAristaPtr();
			while(Arco)
			{
				if(Arco->GetDestino() == Vertice)
				{
					EliminarArista(Aux->GetNom(),Arco->GetDestino()->GetNom()); 
					break; 
				}
				Arco = Arco->GetSigArista();
			} 
			Aux = Aux->GetSigNodo();  
		}
		if(GetInicio() == Vertice)
		{
			SetInicio(Aux->GetSigNodo()); 
			delete Aux; 
		}
		else
		{
			Aux = GetInicio(); 
			Nodo * Ant = NULL; 
			while(Aux != Vertice)
			{
				Ant = Aux ; 
				Aux = Aux->GetSigNodo();  
			}
			Ant->SetSigNodo(Aux->GetSigNodo()); 
			Aux->SetSigNodo(NULL);
			delete Aux;  
		}
	} 
} 
void Grafo::LeerNodos(string S)
{
	string Nom; 
	ifstream Entrada(S.c_str()); 
	while(!Entrada.eof() && Entrada>>Nom)
	{
		InsertarNodo(Nom); 
	}
}
void Grafo::LeerAristas(string S)
{
	string Ori,Des;
	int Pe;  
	ifstream Entrada(S.c_str()); 
	while(!Entrada.eof() && Entrada>>Ori>>Des>>Pe)
	{
		InsertarArista(Ori,Des,Pe);
	}
} 
void Grafo::GuardarGrafo(string S)
{
	ofstream Save(S.c_str());
	if(!GetInicio())
	{
		cout << "\tGrafo Vacio " << endl ; 
	}
	else
	{
		Nodo * Aux(Inicio);
		while(Aux)
		{
			if(!Aux->GetAristaPtr())
			{
				Aux = Aux->GetSigNodo();  
			}
			else
			{
				Arista * temp = Aux->GetAristaPtr();
				while(temp)
				{
					Save << Aux->GetNom() << " - " ; 
					Save << temp->GetDestino()->GetNom() <<" - "<< temp->GetPeso() << endl; 
					temp = temp->GetSigArista();
				}
			}
			Aux = Aux->GetSigNodo();  
		}
	}
}
void Grafo::GuardarNodos(string S)
{
	ofstream Save(S.c_str()); 
	if(!GetInicio())
	{
		cout << "\tGrafo Vacio " << endl ; 
	}
	else
	{
		Nodo * Aux(Inicio);
		while(Aux)
		{
			Save << Aux->GetNom() << endl; 
			Aux = Aux->GetSigNodo();  
		}
	}
}
void menu(Grafo &G)
{
	bool band = 0 ; 
    int op = 0; 
    string var_1 ;
	string var_2 ; 
	do
	{
		system("cls");
		cout << endl<<endl; 
    	cout << "\t       --MENU GRAFO--" <<  endl ; 
	    cout << endl ; 
	    cout << "\t\t1-Leer Nodos  " << endl ; 
	    cout << "\t\t2-Leer Aristas " << endl ; 
	    cout << "\t\t3-Mostrar Grafo " << endl ; 
	    cout << "\t\t4-Eliminar Nodo " << endl ; 
	    cout << "\t\t5-Eliminar Arista " << endl ;
		cout << "\t\t6-Guardar Nodos" << endl ;  
		cout << "\t\t7-Guardar Aristas  " << endl ; 
	    cout << "\t\t8-Salir" << endl ; 
	    cout << endl ; 
	    cout <<"Elige una opcion: "; 
	    cin >> op ; 
		switch(op)
		{
			case 1:
				cout << "\n\t\t         LEER NODOS " << endl ;
				cout << "\t Ingrese el nombre del Archivo con extencion" << endl;
				cin >> var_1; 
				G.LeerNodos(var_1);
				system("PAUSE");
				break ;
			case 2:
				cout << "\n\t\t         LEER ARISTAS " << endl ; 
				cout << "\t Ingrese el nombre del Archivo con extencion" << endl;
				cin >> var_1; 
				G.LeerAristas(var_1);
				system("PAUSE");
				break ;
			case 3:
				G.MostrarGrafo();
				system("PAUSE"); 
				break ;
			case 4: 
			    cout << "\n\t\t  ELIMINAR NODO " << endl ;
			    cout << "\t Ingrese Nombre del nodo a eliminar " << endl; 
			    cin >> var_1 ; 
				G.EliminarNodo(var_1);
				system("PAUSE"); 
				break ;
			case 5:
				cout << "\n\t  ELIMINAR ARISTA  " << endl ;
				cout << "\t Ingrese el Origen " << endl;
				cin >> var_1; 
				cout << "\t Ingrese el Destino " << endl;
				cin >> var_2; 
				G.EliminarArista(var_1,var_2);
				system("PAUSE");
				break ;
			case 6:
				cout << "\n\t\t      GUARDAR NODOS " <<endl ; 
				cout << "\t Ingrese el nombre del Archivo con extencion" << endl;
				cin >> var_1; 
				G.GuardarNodos(var_1);
			    system("PAUSE");
				break;
			case 7:
				cout << "\n\t\t      GUARDAR ARISTAS  " <<endl ; 
				cout << "\t Ingrese el nombre del Archivo con  extencion" << endl;
				cin >> var_1; 
				G.GuardarGrafo(var_1);
			    system("PAUSE");
				break; 		
			case 8:
				band = 1; 
				break; 	    	
			default:
				cout << "\tOpcion no valida " << endl ; 
				system("PAUSE");
			    break ;	
		}	
	}
	while(!band); 
}









