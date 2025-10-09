// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 8
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string correo;
    int posArroba, posPunto;
    cout<<"Ingrese una direccion de correo: ";
    cin>>correo;
    posArroba=correo.find('@');
    posPunto=correo.find('.',posArroba+1);
    if(posArroba!=-1&&posPunto!=-1&&correo.find('@',posArroba+1)==-1){//es un if el cual pide varias condiciones para que actue. que el arroba y el punto sea distinto a -1
        cout<<"Correo electronico valido"<<endl;
    } else {
        cout<<"Correo electronico invalido"<<endl;
    }
    return 0;
}
