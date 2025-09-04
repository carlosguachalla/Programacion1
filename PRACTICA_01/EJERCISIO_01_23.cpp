// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 23
#include<iostream>
using namespace std;
int main(){
    int num1=0, contador=0, resultado=0;
    cout<<"Introduce un numero entero: ";
    cin>>num1;
    while(num1!=0){//se utiliza esto para repetir el proceso hasta que llegue a 0
        cout<<num1%10;//usamos esto para mostrar el ultimo digito del numero
        num1=num1/10;// usamos esto para quitar el ultimo digito del numero
    }
}