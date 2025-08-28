// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;
int main() {
    int numero=0;
    cout<<"Ingrese un numero entero: ";
    cin>>numero;
    if(numero>0)//usamos este if par ver si el numero es mayor a cero
        cout<<"el numero es positivo"<<endl;
    if(numero<0)//usamos este if par ver si el numero es menor a cero
        cout<<"el numero es negativo"<<endl;
    if(numero==0)//usamos este if par ver si el numero es cero
        cout<<"el numero es cero"<<endl;
    return 0;
}