// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 7
#include <iostream>
#include <vector>
using namespace std;
int sumacuadrados(int n){
    if (n == 0){ // Caso base
        return 0;
    } else {
        return (n * n) + sumacuadrados(n - 1);//retorna el valor n * n + la llamada recursiva con n - 1
    }
}
int main(){
    int numero, resultado;
    cout<<"Ingrese un número entero: ";
    cin>>numero;
    resultado=sumacuadrados(numero);
    cout<<"La suma de los cuadrados de los números desde 1 hasta "<<numero<<" es: "<< resultado;
    return 0;
}