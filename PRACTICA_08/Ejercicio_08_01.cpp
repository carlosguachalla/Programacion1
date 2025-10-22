// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;
// Función recursiva que suma los dígitos de un número no negativo
int sumarDigitos(int n){
    if (n == 0){ // Caso base
        return 0;
    } else {
        return (n % 10) + sumarDigitos(n / 10);//retorna el último dígito más la llamada recursiva con el número sin el último dígito
    }
}
int main(){
    int numentero,sumadedigitos=0;
    cout<<"Ingrese un número entero: ";
    cin>>numentero;
    sumadedigitos=sumarDigitos(numentero);
    cout<<"La suma de los dígitos es: "<< sumadedigitos;
}
