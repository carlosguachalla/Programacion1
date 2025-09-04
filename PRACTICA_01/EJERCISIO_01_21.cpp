// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 21
#include<iostream>
using namespace std;
int main(){
    int num1=0, num2=0, contador=0, resultado=0;
    cout<<"Introduce dos numeros enteros: ";
    cin>>num1;
    cin>>num2;
    for(contador=1;contador<=abs(num2);contador++){//con esto hacemos la suma repetidamente haciendo la formula de la multiplicacion sin usar el simbolo *
        resultado=resultado+num1;
    }
    if(num2<0)//enn caso de que el segundo numero sea negativo con esto nos aseguramos que el numero sea  correcto
        resultado=resultado-resultado-resultado;
    cout<<"el resultado de la multiplicacion es: "<<resultado;
}