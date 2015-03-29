#ifndef _RECTANGULO_H_
#define _RECTANGULO_H_

class Rectangulo {
  
    private:
        int alto;
        int ancho;
        int perim;

    public:
        Rectangulo();
        Rectangulo(int alto, int ancho);
        
        int leer_alto();
        int leer_ancho();
        // En el enunciado del ejercicio no se especifica que esta función
        // devuelva el valor que calcula, de modo que el valor calculado lo
        // asigno a la variable perim.
        void perimetro();
        int area();
        bool cuadrado();
        
        void printInformacion(const std::string &rectname);
};


#endif // _RECTANGULO_H_