#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

typedef vector< string > TLinea;
typedef vector< TLinea > TTexto;


int main(int argc, char* argv[]) {

    string path("texto.txt");
    string palabra;
    string linea;

    TTexto ttexto;


    ifstream fichero(path.c_str());
    if (!fichero) {
        cerr << "El archivo no pudo abrirse" << endl;
        exit(1);
    }

    while(getline(fichero, linea)) {
        TLinea tlinea;
        for(int i = 0; i <= linea.length(); i++) {
            char c = linea[i];
            if(c == ' ' || c == '\n' || i == linea.length()) {
                tlinea.push_back(palabra);
                palabra = "";
            }
            else {
                palabra = palabra + c;
            }
        }
        ttexto.push_back(tlinea);
    }

    cout << "Contenido del fichero : " << endl << endl;
    for(vector< TLinea >::iterator it = ttexto.begin(); it != ttexto.end(); ++it) {
        for(vector< string >::iterator it2 = it->begin(); it2 != it->end(); ++it2) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }


    fichero.close();


    return 0;
}
