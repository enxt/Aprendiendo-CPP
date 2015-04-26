#include <iostream>

using namespace std;

template < class TArray >
TArray menorArray(TArray[], int);

int main() {
    const int longi_int = 5, longi_float = 6, longi_char = 5;
    int array_int[longi_int] = {1,2,5,3,4};
    float array_float[longi_float] = {2.2, 5.5, 6.6, 3.3, 4.4, 1.1};
    char array_char[longi_char] = {'A','D','I','O','S'};

    cout << "el menor del array de enteros es " << menorArray(array_int, longi_int) << endl;
    cout << "el menor del array de float es " << menorArray(array_float, longi_float) << endl;
    cout << "el menor del array de char es " << menorArray(array_char, longi_char) << endl;

    return 0;
}

template < class TArray >
TArray menorArray(TArray v1[], int long_int) {
    TArray resp = v1[0];
    for(int i = 1; i < long_int; i++) {
        if(v1[i] < resp) resp = v1[i];
    }

    return resp;
}