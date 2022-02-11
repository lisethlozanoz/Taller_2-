#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>


using namespace std;

struct Herramienta{ //////No entiendo como se usarían las estructuras
	int numeroRegistro, cantidad, costoUnitario;
	string nombreHerramienta; //Se puede trabajar con string
};

int menu(); //Para mostrar y escanear las opciones del menu 

int lectura(Herramienta herramientas[100]); //Opcion 1 -> Leer el archivo
///////No imprime nada -> Como se que esa parte esta funcionando?

void listarHerramientas(Herramienta herramientas[100], int tam); //Opcion 2 -> Imprimir el archivo

void insertarFinal(Herramienta herramientas[100], int tam); //Opcion 3 -> Agregar texto al final
////////No funciona con espacios

void eliminarHerramienta (Herramienta herramientas[100], int tam); //Opcion 4 -> Eliminar una herramienta y actualizar archivo

void generarArchivo(Herramienta herramientas[100], int tam); //Opcion 5 -> Crear archivo con valores superiores a un millon



int main(){
	
	Herramienta herramientas [100];
	ofstream Esc;
    ifstream Lec;
    int op, tam;

	do{
	    op= menu();
	    switch(op){
	    	case 1:
	    		tam = lectura(herramientas);
	    		break;
	    	case 2:
	    		listarHerramientas(herramientas, tam);
	    		break;
	    	case 3:
	    		insertarFinal(Esc);
	    		tam = listarHerramientas(herramientas, tam);
	    		break;
	    	case 4:
	    		eliminarHerramienta(Lec);
	    		tam = listarHerramientas(herramientas, tam);
	    		break;
	    	case 5:
	    		generarArchivo(herramientas, tam);
		    	tam = listarHerramientas(herramientas, tam); //No me imprime nada
	    		break;
	    	case 6:
	    		break;
		}
			
	}while(op!=6);
	
	return 0;
	
}


int menu(){
	
	int x;
	
	cout<<"Bienvenido al menu"<<endl<<endl;
	cout<<"Ingrese 1 para capturar datos iniciales de las herramientas desde un archivo."<<endl<<endl;
	cout<<"Ingrese 2 para listar las herramientas."<<endl<<endl;
	cout<<"Ingrese 3 para insertar al final una herramienta de forma manual."<<endl<<endl;
	cout<<"Ingrese 4 para eliminar una herramienta y actualizar archivo."<<endl<<endl;
	cout<<"Ingrese 5 para generar archivo con herramientas por encima del 1000000 Ordenado."<<endl<<endl;
	cout<<"Ingrese 6 para salir del programa"<<endl<<endl;
	cin>>x;
	
	return x;	
}

int lectura(Herramienta herramientas[100]){ //////Aqui no se debe poner ifstream &Lec? -> En que casos se debe usar?
    fstream archivo;
	archivo.open("Herram.txt", ios::in);
	int i = 0;
	
	int registroHerramienta, cantidadHerramienta, costoUnitarioHerramienta;
    string nombreHerramienta;
    
	   
	Herramienta herramienta;
	if(archivo.is_open()) 
    {
        cout<<"Herramientas registradas"<<endl;
        
        while(!archivo.eof())
        {
        	
        	archivo>>registroHerramienta;
        	herramientas[i].numeroRegistro = registroHerramienta;
        	
            archivo>>nombreHerramienta;
            herramientas[i].nombreHerramienta = nombreHerramienta;
            	
            archivo>>cantidadHerramienta;
            herramientas[i].cantidad = cantidadHerramienta;
            
            archivo>>costoUnitarioHerramienta;
            herramientas[i].costoUnitario = costoUnitarioHerramienta;
           
            i++;
        }
        //archivo.close();
    }
    else 
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    system("pause");	
	
	/*if(archivo.fail()){ //////En este caso que tengo varias funciones que trabajan con el archivo, igual debo poner esta instruccion en cada una?
		cout<<"No se pudo abrir el archivo"<<endl<<endl;
		exit(1);
	}*/
	
	archivo.close();
	return i;
}

void listarHerramientas(Herramienta herramientas[100], int tam){
	
	for(int i =0; i < tam; i++){
		cout<<herramientas[i].numeroRegistro<<endl;
		cout<<herramientas[i].cantidad<<endl;
		cout<<herramientas[i].costoUnitario<<endl;
		cout<<herramientas[i].nombreHerramienta<<endl;
	}
	
}

void insertarFinal(ofstream &Esc){	

    
    int registroHerramienta, cantidadHerramienta, costoUnitarioHerramienta;
    string nombreHerramienta;
    
    Esc.open("Herram.txt", ios::app);
	
	cout<<"Ingrese el numero de registro de la herramienta que desea agregar"<<endl<<endl;
	cin>>registroHerramienta;
	
	cout<<"Ingrese el nombre de la herramienta que desea agregar"<<endl<<endl;
	cin>>nombreHerramienta;
	
	cout<<"Ingrese la cantidad de la herramienta que desea agregar"<<endl<<endl;
	cin>>cantidadHerramienta;
	
	cout<<"Ingrese el costo unitario de la herramienta que desea agregar"<<endl<<endl;
	cin>>costoUnitarioHerramienta;
	
	Esc<<endl<<registroHerramienta<<" ";
	Esc<<nombreHerramienta<<" ";
	Esc<<cantidadHerramienta<<" ";
	Esc<<costoUnitarioHerramienta;
	
	Esc.close();
}

void eliminarHerramienta(ifstream &Lec){
	int registroHerramienta, cantidadHerramienta, costoUnitarioHerramienta, registroAux;
    string nombreHerramienta;
    bool encontrarHerramienta=false;
    
    Lec.open("Herram.txt", ios::in);
    ofstream archivoAux("auxiliar.txt", ios::out);
    
    if(Lec.is_open())
    {
        cout<<"Ingrese el numero de registro de la herramienta que desea borrar: "<<endl;
        cin>>registroAux;
        Lec>>registroHerramienta;
        while(!Lec.eof())
        {
            Lec>>nombreHerramienta;
            Lec>>cantidadHerramienta;
            Lec>>costoUnitarioHerramienta;
            if(registroHerramienta == registroAux)
            {
                encontrarHerramienta = true;
                cout<<"Registro eliminado";
            }
            else
            {
                archivoAux<<registroHerramienta<<endl;
				archivoAux<<nombreHerramienta<<endl;
				archivoAux<<cantidadHerramienta<<endl;
				archivoAux<<costoUnitarioHerramienta<<endl;
            }
            Lec>>registroHerramienta;
        }
        Lec.close();
        archivoAux.close();

        if(encontrarHerramienta!=true)
        {
            cout<<"Registro no encontrado";
        }
    }
    else
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    remove("Herram.txt");
    rename("auxiliar.txt", "Herram.txt");
	
}

void generarArchivo (Herramienta herramientas[100], int tam){
   
   ofstream nuevoArchivo("sal.txt", ios::out);
   
	for(int i = 0; i < tam; i++){
		if(herramientas[i].costoUnitario > 1000000){
			nuevoArchivo<<herramientas[i].numeroRegistro<< " ";
			nuevoArchivo<<herramientas[i].nombreHerramienta<< " ";
    		nuevoArchivo<<herramientas[i].cantidad<< " ";
    		nuevoArchivo<<herramientas[i].costoUnitario<< " "<<endl;
    		
		}
	}
	nuevoArchivo.close();

}
