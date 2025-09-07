// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 3
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int naleatorio=0, contador=0, factorial=1;
    srand(time(0)); // ponemos una semilla
    naleatorio = rand() % 10 + 1; // Genera un número entre 1 y 10
    cout << naleatorio <<endl;
    for(contador=1;contador<=naleatorio;contador++){
        factorial=factorial*contador;
    }
    cout<<"El factorial del numero aleatorio es: "<<factorial<<endl;
    return 0;
}