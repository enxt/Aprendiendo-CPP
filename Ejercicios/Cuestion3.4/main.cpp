#include <iostream>
#include <set>

using namespace std;

typedef set< string, less<string> > TListaNombres;

int main(int argc, char* argv[]) {

    string nombre;
    TListaNombres nombres;

    cout << "Escriba los nombres. Para acabar dejar en blanco." << endl << endl;
    nombres.clear();
    while(true) {
        cout << "¿Nombre? ";
        getline(cin, nombre);
        if(nombre.empty()) break;
        nombres.insert(nombre);
    }

    if(nombres.size() > 0) {
        cout << endl << endl;
        for(set< string, less<string> >::iterator iter = nombres.begin(); iter != nombres.end(); ++iter) {
            cout << *iter << endl;
        }
    }

    return 0;
}
