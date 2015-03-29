#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "funciones.h"

using namespace std;

struct data {
	string nombre;
	string apellido;
	string edad;
};

int main(int argc, char * argv[]) {

	data t;
	string nombreArchivo;
	nombreArchivo = string("datos.txt");
	
	ofstream archDatos(nombreArchivo.c_str());
    if (!archDatos) {
        cerr << "El archivo no pudo abrirse" << endl;
        exit(1);
    }
	
	do {
		getVariable(&t.nombre, "Nombre", true, 80, false);
		if(t.nombre.empty()) break;
		getVariable(&t.apellido, "Apellido", false, 80, false);
		getVariable(&t.edad, "Edad", false, 3, true);
		
		cout << endl << "Registro: " << t.nombre << " " << t.apellido << " " << t.edad << endl << endl;
		archDatos << t.nombre << " " << t.apellido << " " << t.edad << "\n";
	}
	while(true);
	
	archDatos.close();
	
	return 0;
}

