// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 12
#include <iostream>
using namespace std;
int main() {
    int numero=0;
    while(numero<1 || numero>5){//este while hace que se repita la instruccion hasta que se introduzca un numero entre el 1 y el 5
        cout<<"Ingrese un numero: ";
        cin>>numero;
    }
    return 0;
}