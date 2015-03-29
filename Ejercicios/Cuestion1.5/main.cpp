#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[]) {
	char c;
	string fname;
	string slinea;
	string spalabra("");
	ifstream fichero;
	
	cout << "Escriba el nombre del fichero a tratar: ";
	cin >> fname;
	cin.get(c);
	
	fichero.open(fname.c_str());
	
	if(!fichero) {
		cout << "Error: no se pudo abrir el fichero " << fname << endl;
		return 0;
	}
	
	cout << "Tratando fichero: " << fname << endl << endl;
	
	while(!fichero.eof()) {
		getline(fichero, slinea);

		int cp = 0; // Comienzo palabra
		
		for(int i = 0; i <= slinea.length(); i++) {
			// Cuando se cumple, tengo una palabra entre las posiciones "cp" a "i"
			if(slinea[i] == ' ' || slinea[i] == '\n' || slinea[i] == '.' || slinea[i] == ',' || i == slinea.length()) { 
				spalabra = slinea.substr(cp, i-cp);
				if(spalabra.length() > 0 && spalabra != " " && spalabra.substr(0,1).find_first_of("aeiouAEIOUáéíóúÁÉÍÓÚ") == 0)
					cout << spalabra << endl;
				cp = i+1;
			}
		}
	}
	
	
	
	return 0;
}