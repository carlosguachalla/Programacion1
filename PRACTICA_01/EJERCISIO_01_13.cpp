// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 13
#include <iostream>
using namespace std;
int main() {
    int numero=0, nuevonumero=0, contador=0;
    cout<<"Ingrese un numero: ";
    cin>>numero;
    while(contador!=numero){//con todo este while hacemos que la suma de terminos se repita hasta que el contaador sea igual al numero ingresado
        contador=contador+1;
        nuevonumero=nuevonumero+contador;
    }
    cout<<"Resulta: "<<nuevonumero<<endl;
    return 0;
}