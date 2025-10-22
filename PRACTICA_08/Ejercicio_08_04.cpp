// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 4
#include <iostream>
using namespace std;
int MaximoComunDivisor(int a, int b){
    if (b == 0){ // Caso base
        return a;
    } else {
        return MaximoComunDivisor(b, a % b);//llama recursivamente con b y el residuo de a dividido b
    }
}
int main(){
    int num1, num2, mcd;
    cout<<"Ingrese el primer número entero: ";
    cin>>num1;
    cout<<"Ingrese el segundo número entero: ";
    cin>>num2;
    mcd=MaximoComunDivisor(num1,num2);
    cout<<"El Máximo Común Divisor de "<<num1<<" y "<<num2<<" es: "<< mcd;
    return 0;
}