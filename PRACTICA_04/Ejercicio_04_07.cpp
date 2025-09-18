// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 14/09/2025
// Número de ejercicio: 7
#include <iostream>
using namespace std;
int MCD(int num1, int num2) {//halla el maximo comun divisor
    int temp;
    while (num2!=0) {
        temp=num2;
        num2=num1%num2;
        num1=temp;
    }
    return num1;
}
int MCM(int num1, int num2) {//con esta funcion calculamos el minimo comun multiplo llamando antes el maximo comun divisor
    return (num1*num2)/MCD(num1,num2);
}
int main() {
    int num1=0, num2=0;
    cout<<"Ingresar un numero: ";
    cin>>num1;
    cout<<"Ingresar otro numero: ";
    cin>>num2;
    cout<<"El MCM entre "<<num1<<" y "<<num2<<" es: "<<MCM(num1,num2)<<endl;
    cout<<"El MCD entre "<<num1<<" y "<<num2<<" es: "<<MCD(num1,num2)<<endl;
}