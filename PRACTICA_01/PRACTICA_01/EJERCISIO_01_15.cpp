// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 28/08/2025
// Número de ejercicio: 15
#include <iostream>
using namespace std;
int main() {
    float numnotas=0, notas=0, sumanotas=0, promedio=0, contador=0;
    cout<<"Ingrese el numero de notas que va ingresar: ";
    cin>>numnotas;
    while(contador!=numnotas){//con este while hacemos que se repita el numero de veces indicado la instruccion de introducir nota
        cout<<"Ingrese una nota: ";
        cin>>notas; 
        sumanotas=sumanotas+notas;//en esta variable guardamos la sumatoria de notas
        contador=contador+1;
    }
    promedio=sumanotas/numnotas;//la division entre la suma de todas las notas y el numero de notas ingresadas
    cout<<"Promedio total: "<<promedio<<endl;
    return 0;

}