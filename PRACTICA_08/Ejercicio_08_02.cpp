// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 2
#include <iostream>
using namespace std;
int potencia(int base, int exponente){
    if (exponente == 0){ // Caso base
        return 1;
    } else {
        return base * potencia(base, exponente - 1);//retorna la base multiplicada por la llamada recursiva con exponente - 1
    }
}
int main(){
    int base, exponente, resultado;
    cout<<"Ingrese la base: ";
    cin>>base;
    cout<<"Ingrese el exponente: ";
    cin>>exponente;
    resultado=potencia(base,exponente);
    cout<<"El resultado de "<<base<<" elevado a la "<<exponente<<" es: "<< resultado;
}