#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char * argv[]) {
    
    
    string nombreArchivo("datos.txt");
    
    ifstream archDatos(nombreArchivo.c_str());
    if (!archDatos) {
        cerr << "El archivo no pudo abrirse" << endl;
        exit(1);
    }
    
    string nombre;
    string apellido;
    int edad;
    while( archDatos >> nombre >> apellido >> edad) {
        if(edad >= 30)
            cout << nombre << " " << apellido << '\n';
    }
    
    archDatos.close();
    return 0;
    
}