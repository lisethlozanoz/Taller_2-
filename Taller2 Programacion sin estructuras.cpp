#include <iostream>
#include <fstream>
#include <stdio.h>


using namespace std;

struct Herramientas{ //////No entiendo como se usarían las estructuras
	int numeroRegistro, cantidad, costoUnitario;
	char nombreHerramienta [20]; //Se puede trabajar con string
};

int menu(); //Para mostrar y escanear las opciones del menu 

void lectura(); //Opcion 1 -> Leer el archivo
///////No imprime nada -> Como se que esa parte esta funcionando?

void listarHerramientas(ifstream &Lec); //Opcion 2 -> Imprimir el archivo

void insertarFinal(ofstream &es); //Opcion 3 -> Agregar texto al final
////////No funciona con espacios


void eliminarHerramienta (ifstream &Lec); //Opcion 4 -> Eliminar una herramienta y actualizar archivo

void generarArchivo(ifstream &Lec); //Opcion 5 -> Crear archivo con valores superiores a un millon



int main(){
	
	
	Herramientas herramientas [100];
	ofstream Esc;
    ifstream Lec;
    int op;

		
	do{
		
	    op= menu();
		if(op==1){
		    lectura();
	    }
	
	    else if(op==2){
	    	listarHerramientas(Lec);
	    }
	
	    else if(op==3){
	    	insertarFinal(Esc);
	    	listarHerramientas(Lec);
	    }
	
	    else if(op==4){
	    	eliminarHerramienta(Lec);
	    	listarHerramientas(Lec);
	    }
	
	    else if(op==5){
		    generarArchivo(Lec);
		    listarHerramientas(Lec); //No me imprime nada
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

void lectura(){ //////Aqui no se debe poner ifstream &Lec? -> En que casos se debe usar?
    fstream archivo;
	archivo.open("Herram.txt", ios::in);
	
	if(archivo.fail()){ //////En este caso que tengo varias funciones que trabajan con el archivo, igual debo poner esta instruccion en cada una?
		cout<<"No se pudo abrir el archivo"<<endl<<endl;
		exit(1);
	}
	
	archivo.close();
}

void listarHerramientas(ifstream &Lec){
	
	int registroHerramienta, cantidadHerramienta, costoUnitarioHerramienta;
    string nombreHerramienta;
    
    Lec.open("Herram.txt", ios::in);
	   
	
	if(Lec.is_open()) 
    {
        cout<<"Herramientas registradas"<<endl;
        Lec>>registroHerramienta; /////No entiendo esta instruccion
        while(!Lec.eof())
        {
            Lec>>nombreHerramienta;
            Lec>>cantidadHerramienta;
            Lec>>costoUnitarioHerramienta;
            cout<<"Numero de registro: "<<registroHerramienta<<endl;
            cout<<"Nombre de la herramienta: "<<nombreHerramienta<<endl;
            cout<<"Cantidad de la herramienta: "<<cantidadHerramienta<<endl;
            cout<<"Costo unitario de la herramienta: "<<costoUnitarioHerramienta<<endl;
            cout<<"---------------"<<endl;
            Lec>>registroHerramienta;
        }
        Lec.close();
    }
    else 
    {
        cout<<"Error al abrir el archivo"<<endl;
    }
    system("pause");	
	
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
	
	Esc<<registroHerramienta<<endl;
	Esc<<nombreHerramienta<<endl;
	Esc<<cantidadHerramienta<<endl;
	Esc<<costoUnitarioHerramienta<<endl;
	
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

void generarArchivo (ifstream &Lec){
	
	Lec.open("Herram.txt", ios::in);
    ofstream nuevoArchivo("sal.txt", ios::out);
    int registroHerramienta, cantidadHerramienta, costoUnitarioHerramienta;
    string nombreHerramienta;
    
	
	if(Lec.is_open()){
		Lec>>registroHerramienta;
		while(!Lec.eof()){
        	Lec>>nombreHerramienta;
        	Lec>>cantidadHerramienta;
        	Lec>>costoUnitarioHerramienta;
        	
        	if(registroHerramienta>1000000){
        		nuevoArchivo<<registroHerramienta;
        		nuevoArchivo<<nombreHerramienta;
        		nuevoArchivo<<cantidadHerramienta;
        		nuevoArchivo<<costoUnitarioHerramienta;
			}
        	
        }

	}
	
	else{
		cout<<"Error al abrir el archivo"<<endl;
	}
	

}




