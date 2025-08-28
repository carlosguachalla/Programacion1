// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 27/08/2025
// Número de ejercicio: 7

#include <iostream>
using namespace std;
int main() {
    string letra;
    cout<<"Ingrese una letra minuscula:";
    cin>>letra;
    if(letra=="a"||letra=="e"||letra=="i"||letra=="o"||letra=="u")//con este if se compara si la letra es una vocal
        cout<<"La letra es vocal"<<endl;
    if(letra>="a"&&letra<="z") { //con este if comprobamos que la letra sea una letra y no un caracter especial
        if(letra!="a"&&letra!="e"&&letra!="i"&&letra!="o"&&letra!="u")//este if comprueba que la letra es una consonante
            cout<<"La letra es consonante"<<endl;
    }
    else{//en caso de no ser una letra de "a" a "z" muestra esto
         cout<<"La letra es un caracter especial"<<endl;
    }
    return 0;
}