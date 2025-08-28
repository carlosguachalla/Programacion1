// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 28/08/2025
// Número de ejercicio: 14

#include <iostream>
using namespace std;

int main() {
    int numero=0, contador1=0, contador2=0;
    cout<<"Ingrese un numero:";
    cin>>numero;
    while (numero!=contador1)//un primer contador para determinar el numero de filas a colocar
    {
        contador1=contador1+1;
        while (contador2!=contador1){//un segundo contador para saber cuantos caracteres colocar en cada fila
            contador2=contador2+1;
            cout<<"*";
        }
        cout<<endl;
        contador2=0;
    }
    
}