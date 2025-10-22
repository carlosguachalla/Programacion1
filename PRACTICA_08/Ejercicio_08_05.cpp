// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 5
#include <iostream>
#include <vector>
using namespace std;
int Sumatoria(vector<int> &numeros, int n){
    if (n <= 0){ // Caso base
        return 0;
    } else {
        return numeros[n - 1] + Sumatoria(numeros, n - 1);//retorna el ultimo elemento del vector + la llamada recursiva con n-1
    }
}
int main(){
    vector<int> numeros;
    int n, suma=0;
    cout<<"Ingrese el numero de elementos del arreglo: ";
    cin>>n;
    numeros.resize(n);
    for (int i = 0; i < n; i++){
        cout<<"Ingrese el elemento "<<i+1<<": ";
        cin>>numeros[i];
    }
    suma=Sumatoria(numeros, n);
    cout<<"La suma de los elementos del arreglo es: "<< suma;
    return 0;
}