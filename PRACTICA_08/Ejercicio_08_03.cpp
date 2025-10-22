// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int fibonacii(int n){
    if (n == 0){ // Caso base
        return 0;
    } else if (n == 1){ // Caso base hay dos porque los dos primeros terminos son 0 y 1
        return 1;
    } else {
        return fibonacii(n - 1) + fibonacii(n - 2);//retorna la suma de las dos llamadas recursivas anteriores
    }
}
int main(){
    int n, resultado;
    cout<<"Ingrese un número entero: ";
    cin>>n;
    resultado=fibonacii(n);
    cout<<"El término "<<n<<" de la serie de Fibonacci es: "<< resultado;
    return 0;
}