#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int numFilas;
    char temp;
    cout << "Introduzca el número de filas: ";
    cin >> numFilas;
    cin.get(temp);
    
    while(cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Introduzca un número entero mayor a 0: ";
        cin >> numFilas;
        cin.get(temp);
    }
    
    for (int i = 1; i <= numFilas; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i;
        }
        cout << endl;
    }
    
    return 0;
}