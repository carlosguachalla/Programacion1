// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 8
#include <iostream>
using namespace std;
int main() {
    int numero=0;
    cout<<"Ingrese un numero entero: ";
    cin>>numero;
    if(numero%2==1)//este if sucede si el residuo de dividir el numero entre 2 es 1
        cout<<"el numero es impar"<<endl;
    if(numero%2==0)//este if sucede si el residuo de dividir el numero entre 2 es 0
        cout<<"el numero es par"<<endl;
    return 0;
}