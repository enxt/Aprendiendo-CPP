#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef set< string, less<string> > THermanos;
typedef map< string, THermanos, less<string> > TListaPersonas;

int main(int argc, char* argv[]) {
    string nombre;
    THermanos hermanos;
    TListaPersonas personas;

    cout << "Escriba los nombres. Para acabar dejar en blanco." << endl << endl;
    hermanos.clear();
    while(true) {
        cout << "¿Nombre? ";
        getline(cin, nombre);
        if(nombre.empty()) break;

        hermanos.insert(nombre);
        //personas.insert(TListaPersonas::value_type(nombre, hermanos));
    }

    // Esto es lo que interpreto que hay que hacer en el ejercicio
    for(set< string, less<string> >::iterator it = hermanos.begin(); it != hermanos.end(); ++it) {
        personas.insert(TListaPersonas::value_type(*it, hermanos));
    }

    for(set< string, less<string> >::iterator it1 = hermanos.begin(); it1 != hermanos.end(); ++it1) {
        cout << "Hermanos de " << *it1 << ":" << endl;
        map< string, THermanos, less<string> >::iterator it2 = personas.find(string(*it1));
        THermanos h = it2->second;
        for(set< string, less<string> >::iterator it3 = h.begin(); it3 != h.end(); ++it3) {
            cout << *it3 << endl;
        }
    }

    return 0;
}
