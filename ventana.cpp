#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstdlib>
using namespace std; 
void clearScreen() {
    system("cls"); 
}
int menuprincipal() {
	int opcion;
	clearScreen();
	cout<<"-----------------\n";
	cout<<" MENU PRINCIPAL\n";
	cout<<"-----------------\n";
	cout<<"1. Crear Archivo\n";
	cout<<"2. Llenar Archivo\n";
	cout<<"3. Leer Archivo\n";
	cout<<"4. SALIR\n";
	
	cout<<"INGRESE LA OPCION(1/2/3/4): \n";
	cin>>opcion;
	return opcion;
}
void creararchivo(){
	ofstream archivo;
	string nombrearchivo;
	
	cout<<"Ingrese el nombre del archivo a crear: "; 
	cin.ignore();
	getline(cin,nombrearchivo);
	
	archivo.open(nombrearchivo.c_str(),ios::out);
	
	if(archivo.fail()){
		cout<<"\nEl archivo no se pudo crear. ";
		exit(1);
	}
	archivo.close();
	
}
void llenararchivo(){
	ofstream archivo;
	string nombrearchivo;
	
	cout<<"Ingrese el nombre del archivo a llenar: ";
	cin.ignore(); 
	getline(cin,nombrearchivo);
	
	archivo.open(nombrearchivo.c_str(),ios::out);
	
	if(archivo.fail()){
		cout<<"El archivo no se pudo llenar. ";
		exit(1);
	}
	else{
		string continuar;
		do{
			string frase;
			
			cout<<"Ingrese la frase : "<<endl;
			getline(cin,frase);
			
			archivo<<frase<<endl;
			
			cout<<"Continuar? (si/no)";
			
			getline(cin,continuar);
		}while(continuar=="si");
	}
	archivo.close();
	
}
void lecturadelarchivo(){
	ifstream archivo;
	string ubicacion;
	string texto;
	cout<<"Ingrese la ubicacion o nombre del archivo a leer: "<<endl;
	cin.ignore();
	getline(cin,ubicacion);
	
	archivo.open(ubicacion.c_str(),ios::in);
	
	if(archivo.fail()){
		cout<<"no se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	archivo.close();
}
int main(){
	int opcion=0;
	opcion=menuprincipal();
	switch (opcion) {
		case 1:
			clearScreen();
			cout<<"---------------------\n";
			cout<<"CREACION DE ARCHIVO :\n";
			cout<<"---------------------\n";
			creararchivo();
			break;
		case 2:
			clearScreen();
			cout<<"---------------------\n";
			cout<<"LLENAR ARCHIVO :\n";
			cout<<"---------------------\n";
			llenararchivo();
			
			break;
		case 3:
		 	clearScreen();
			cout<<"---------------------\n";
			cout<<"LEER ARCHIVO :\n";
			cout<<"---------------------\n";
			lecturadelarchivo();
		 
			break;
		case 4:
			return 0;
			break;
		default:
                clearScreen(); 
                cout << "Opcion no valida. Intente de nuevo.\n";
                cout << "Presione cualquier tecla para continuar...";
                cin.ignore().get(); 
                break;
	}
	return 0;
}
