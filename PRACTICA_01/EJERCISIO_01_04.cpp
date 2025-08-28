// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
int main() {
    float radio=0, volumen=0, pi=3.1416;//colocamos el valor de pi de una vez
    cout<<"Ingrese el radio de la esfera: ";
    cin>>radio;
    volumen=(4.0/3.0)*pi*radio*radio*radio;//formula del volumen de una esfera donde colocamos "4.0" y "3.0" para que use su valo decimal
    cout<<"El volumen de la esfera es: "<<volumen<<endl;
    return 0;
}
//En este programa pedimos el radio y con eso hallamos el volumen de la esfera, en la formula tambien se podria incluir
//la libreria de cmath y colocar pow(radio,3) en vez de multiplicar 3 veces el radio por si mismo

